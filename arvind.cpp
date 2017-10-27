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
#include <vector>

using namespace std;

struct patient
{
    string patientName;
    int age;
    char sex;

    string disorder;

    int patientID;
    static int number;

    patient();
    patient(int);
    patient *next;
    patient *prev;

    void prettifyData();
    string prettifyString(string);
    bool isValid(string);
    bool isValid(char);
    bool isValid(int);
};

int patient::number = 0;
patient *head = NULL;
patient *tail = NULL;

static bool error = false;

int main()
{
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

patient::patient()
{
    cin.ignore();
    try
    {
        cout << "Enter patient name.\n";
        getline(cin, patientName);

        cout << "Enter age.\n";
        cin >> age;

        cout << "Enter sex.(M/F)\n";
        cin >> sex;

        cin.ignore();

        cout << "Enter disorder.\n";
        getline(cin, disorder);

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
    prettifyData();

    cout << "Patient has been added to queue. Press any key to continue.\n";
    getch();
}

bool patient::isValid(string x)
{
    int letterCount = 0;
    for(int i = 0; i < x.length(); i++)
    {
        if(isalpha(x[i]))
            letterCount++;
        if(!isalpha(x[i]) && x[i] != ' ')
            return false;
    }
    return letterCount ? true : false;
}

bool patient::isValid(char x)
{
    if(x == 'M' || x == 'm' || x == 'F' || x == 'f') return true;
    else return false;
}

bool patient::isValid(int x)
{
    if(x <= 0 || x >= 120) return false;
    else return true;
}

string patient::prettifyString(string a)
{
    a = " " + a + " ";
    vector <int> nextLetter, prevLetter;
    for(int i = 0; i < a.length() - 1; i++)
    {
        if(a[i] == ' ' && isalpha(a[i + 1])) nextLetter.push_back(i);
        if(isalpha(a[i]) && a[i + 1] == ' ') prevLetter.push_back(i);
    }

    string x;

    int i = 0;

    while(i < nextLetter.size() && i < prevLetter.size())
    {
        string temp = a.substr(nextLetter[i] + 1, prevLetter[i] - nextLetter[i]);
        temp[0] = toupper(temp[0]);
        x += temp + " ";
        i++;
    }

    return x;
}

void patient::prettifyData()
{
    patientName = prettifyString(patientName);
    disorder = prettifyString(disorder);

    if(sex == 'f') sex = 'F';
    if(sex == 'm') sex = 'M';
}
