#ifndef ESSENTIAL_H
#define ESSENTIAL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Patient structure
struct Patient
{
    int id;
    string name;
    int age;
    string disease;
    int priority;
};

// Global patient list
vector<Patient> patients;

// Functions
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
    Patient patient;

    cout << "Enter patient ID: ";
    cin >> patient.id;

    cout << "Enter patient name: ";
    cin >> patient.name;

    cout << "Enter patient age: ";
    cin >> patient.age;

    cout << "Enter disease: ";
    cin >> patient.disease;

    cout << "Enter priority (1 = Emergency, 2 = Normal): ";
    cin >> patient.priority;

    patients.push_back(patient);

    cout << "Patient added successfully." << endl;
}

void waiting_list()
{
    if (patients.empty())
    {
        cout << "No patients in waiting list." << endl;
        return;
    }

    cout << "\n--- WAITING LIST ---" << endl;
    
    for (int i = 0; i < patients.size(); i++)
    {
        cout << "ID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Disease: " << patients[i].disease << endl;
        cout << "Priority: " << patients[i].priority << endl;
        cout << "--------------------" << endl;
    }
}

#endif