/*
Queue Management System
This Project implements a Hospital QMS using doubly linked lists.
A Database is stored as a file, that allows to directly enter patient details via ID.
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <cstdlib>
using namespace std;

/* A Singleton class to get id

class identity
{
    static identity *instance;
    identity();

    pulbic:
    int id;
    static identity *make_instance();
};

*/

struct patient
{
    string patient_name;
    int patient_id;
    int age;
    char sex;

    string doctor_name;
    string disorder;

    static int number;

    patient();
    patient(int);
    patient *next;
    patient *prev;
};

int patient::number = 0;
patient *head = NULL;
patient *tail = NULL;

int main()
{
    cout << "HOSPITAL MANAGEMENT SYSTEM\n";

    /*
    cout << "Enter username and password.\n";
    string name, password;
    getline(cin, name);
    getline(cin, password);
    */

    while(true)
    {
        cout << "1. Enter new patient details.\n";
        cout << "2. Check Queue.\n";
        cout << "3. Send to doctor.\n";
        cout << "4. Exit.\n";

        int choice;
        cin >> choice;

        switch(choice)
        {
        case 1:
            {
                patient *temp = new patient;
                temp->next = temp->prev = NULL;

                if(head)
                {
                    tail->next = temp;
                    temp->prev = tail;
                    tail = tail->next;
                }

                else
                {
                    head = tail = temp;
                }

                break;
            }

        case 2:
            {
                if(!head)
                {
                    cout << "Queue is empty.\n";
                    break;
                }

                for(patient *i = head; i; i = i->next)
                {
                    cout << "PATIENT NAME : " << i->patient_name << endl;
                    cout << "PATIENT ID : " << i->patient_id << endl;
                    cout << "DISORDER : " << i->disorder << endl;
                    cout << "DOCTOR NAME : " << i->doctor_name << endl;

                    cout << "\n\n\n";
                }
                break;
            }

        case 3:
            {
                patient *temp = head;
                head = head->next;
                cout << temp->patient_name << " has been sent to " << temp->doctor_name << endl;
                delete temp;
                break;
            }

        case 4:
            {
                cout << "Exiting.\n";
                return 0;
            }

        default:
            cout << "Invalid option.\n";

        }
        system("cls");
    }
    return 0;
}

/*
Accepts data for a new patient and saves it to file.
*/

patient::patient()
{
    cout << "Enter patient name, age and sex.\n";
    getline(cin, patient_name);
    cin >> age >> sex;

    cout << "Enter doctor name.\n";
    getline(cin, doctor_name);

    cout << "Enter disorder.\n";
    getline(cin, disorder);

    patient_id = ++number;
    //ofstream writer("database.txt", ios::out | ios::app)
}

/*
Allows to create a new patient from scratch

patient::patient(int x)
{
    ifstream reader("database.txt");



}

Singleton class functions

identity::identity()
{
    ifstream reader("number.txt");
    reader >> id;
    reader.close();
}

identity::make_instance()
{
    if(!instance) instance = new identity;
    else return instance;
}

*/
