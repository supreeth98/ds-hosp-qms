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
#include <cctype>

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
    char patientName[100];
    int age;
    char sex;

    char disorder[100];

    int patientID;
    static int number;

    patient();
    //patient(int);
    patient *next;
    patient *prev;
};

int patient::number = 0;
patient *head = NULL;
patient *tail = NULL;

bool isValid(char[]);
bool isValid(char);
bool isValid(int);

static bool error = false;

int main()
{
    /*
    cout << "Enter username and password.\n";
    string name, password;
    getline(cin, name);
    getline(cin, password);
    */

    while(true)
    {
        cout << "HOSPITAL MANAGEMENT SYSTEM\n";
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

                if(error)
                {
                    delete temp;
                    break;
                }

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
                    cout << "PATIENT NAME : " << i->patientName << endl;
                    cout << "PATIENT SEX : " << i->sex << endl;
                    cout << "PATIENT ID : " << i->patientID << endl;
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
                cout << temp->patientName << " has been sent to the doctor.\n";
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
    try
    {
        cin.getline(patientName, 100);

        cout << "Enter age.\n";
        cin >> age;

        cout << "Enter sex.\n";
        cin >> sex;

        cin.ignore();

        cout << "Enter disorder.\n";
        cin.getline(disorder, 100);

        if(!isValid(patientName) || !isValid(age) || !isValid(sex) || !isValid(disorder))
            throw 101;
    }

    catch(int e)
    {
        cout << "There has been an error in the input. Enter anything to return to menu.\n";
        error = true;
        getch();
        return;
    }

    patientID = ++number;
    error = false;
    //ofstream writer("database.txt", ios::out | ios::app)
}

bool isValid(char x[])
{
    for(int i = 0; i < strlen(x); i++)
        if(!isalpha(x[i])) return false;
    return true;
}

bool isValid(char x)
{
    if(x == 'M' || x == 'm' || x == 'F' || x == 'f') return true;
    else return false;
}

bool isValid(int x)
{
    if(x <= 0 || x >= 120) return false;
    else return true;
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
