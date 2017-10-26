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
    char patient_name[100];
    int age;
    char sex;

    char disorder[100];

    int patient_id;
    static int number;

    patient();
    //patient(int);
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
                    cout << "Your queue is empty!\n";
                    getch();
                    break;
                }

                for(patient *i = head; i; i = i->next)
                {
                    cout << "PATIENT NAME : " << i->patient_name << endl;
                    cout << "PATIENT SEX : " << i->sex << endl;
                    cout << "PATIENT ID : " << i->patient_id << endl;
                    cout << "DISORDER : " << i->disorder << endl;
                    cout << "\n\n";
                }

                getch();

                break;
            }

        case 3:
            {

                if(!head)
                {
                    cout << "Your queue is empty!\n";
                    getch();
                    break;
                }

                patient *temp = head;
                head = head->next;
                cout << temp->patient_name << " has been sent to the doctor.\n";
                delete temp;

                getch();

                break;
            }

        case 4:
            {
                cout << "Exiting.\n";
                return 0;
            }

        default:
            {
                cout << "Invalid option.\n";
                getch();
            }

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
    cin.ignore();
    cout << "Enter patient name\n";
    cin.getline(patient_name, 100);

    cout << "Enter age.\n";
    cin >> age;

    cout << "Enter sex.\n";
    cin >> sex;

    cin.ignore();

    cout << "Enter disorder.\n";
    cin.getline(disorder, 100);

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
