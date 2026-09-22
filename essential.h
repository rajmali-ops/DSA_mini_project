#include <iostream>
#include <string>

using namespace std;

struct Patient
{
    int id;
    string name;
    int age;
    string disease;
    int priority;
};

const int MAX_PATIENTS = 100;

Patient patients[MAX_PATIENTS];
int patientCount = 0;

bool authentication()
{
    string userId;
    string password;

    cout << "Enter User ID: ";
    cin >> userId;

    cout << "Enter Password: ";
    cin >> password;

    if (userId == "admin" && password == "1234")
    {
        cout << "Login successful!" << endl;
        return true;
    }
    else
    {
        cout << "Wrong User ID or Password!" << endl;
        return false;
    }
}

void intake_patient()
{
    if (patientCount >= MAX_PATIENTS)
    {
        cout << "Patient list is full." << endl;
        return;
    }

    cout << "Enter patient ID: ";
    cin >> patients[patientCount].id;

    cout << "Enter patient name: ";
    cin >> patients[patientCount].name;

    cout << "Enter patient age: ";
    cin >> patients[patientCount].age;

    cout << "Enter disease: ";
    cin >> patients[patientCount].disease;

    cout << "Enter priority:" << endl;
    cout << "1 = Emergency" << endl;
    cout << "2 = Serious" << endl;
    cout << "3 = Normal" << endl;
    cout << "Enter priority: ";
    cin >> patients[patientCount].priority;

    patientCount++;

    cout << "Patient added successfully." << endl;
}

void waiting_list()
{
    if (patientCount == 0)
    {
        cout << "No patients in waiting list." << endl;
        return;
    }

    cout << "\n--- WAITING LIST ---" << endl;

    for (int priority = 1; priority <= 3; priority++)
    {
        for (int i = 0; i < patientCount; i++)
        {
            if (patients[i].priority == priority)
            {
                cout << "ID: " << patients[i].id << endl;
                cout << "Name: " << patients[i].name << endl;
                cout << "Age: " << patients[i].age << endl;
                cout << "Disease: " << patients[i].disease << endl;
                cout << "Priority: " << patients[i].priority << endl;
                cout << "--------------------" << endl;
            }
        }
    }
}
