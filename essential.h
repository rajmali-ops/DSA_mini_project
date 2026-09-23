#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string disease;
    int priority; 
    Patient* next; 
};

int authentication() {
    string user, pass;
    cout << "\n--- Login ---" << endl;
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    if (user == "staff" && pass == "staff123") {
        return 1; // Tier-1
    } else if (user == "admin" && pass == "admin123") {
        return 2; // Tier-2
    } else {
        cout << "Wrong password and user-id! Re-try." << endl;
        return 0;
    }
}

void intake_patient(Patient*& front) {
    Patient* newPatient = new Patient();
    
    cout << "\n--- Register New Patient ---" << endl;
    cout << "Patient ID: ";
    cin >> newPatient->id;
    cout << "Name: ";
    cin >> newPatient->name;
    cout << "Age: ";
    cin >> newPatient->age;
    cout << "Disease/Condition: ";
    cin >> newPatient->disease;
    cout << "Priority (1=Emergency, 2=Standard): ";
    cin >> newPatient->priority;
    
    newPatient->next = nullptr;

    if (front == nullptr || front->priority > newPatient->priority) {
        newPatient->next = front;
        front = newPatient;
    } else {
        Patient* temp = front;
        while (temp->next != nullptr && temp->next->priority <= newPatient->priority) {
            temp = temp->next;
        }
        newPatient->next = temp->next;
        temp->next = newPatient;
    }
    cout << "Patient added successfully!" << endl;
}

void waiting_list(Patient* front) {
    if (front == nullptr) {
        cout << "\nThe waiting list is currently empty." << endl;
        return;
    }

    cout << "\n--- Current Waiting List ---" << endl;
    Patient* temp = front;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << " | Priority: " << temp->priority 
             << " | Name: " << temp->name << " | Disease: " << temp->disease << endl;
        temp = temp->next;
    }
}

void archive_patient(Patient* p) {
    ofstream file("history.txt", ios::app); 
    if (file.is_open()) {
        file << "ID: " << p->id << " | Name: " << p->name 
             << " | Age: " << p->age << " | Treated for: " << p->disease << endl;
        file.close();
    } else {
        cout << "Error: Could not open history file!" << endl;
    }
}

void consult_patient(Patient*& front) {
    if (front == nullptr) {
        cout << "\nNo patients in the queue to consult." << endl;
        return;
    }

    Patient* currentPatient = front;
    
    cout << "\n--- Now Consulting ---" << endl;
    cout << "Doctor is seeing: " << currentPatient->name << " (ID: " << currentPatient->id << ")" << endl;
    cout << "Consultation in progress... please wait 30 seconds." << endl;
    
    for(int i = 0; i < 6; i++) {
        this_thread::sleep_for(chrono::seconds(5)); 
        cout << "* ";
        cout.flush(); 
    }
    
    cout << "\nConsultation complete! Discharging patient." << endl;
    archive_patient(currentPatient);

    front = front->next; 
    delete currentPatient; 
}

void lookup_patient(Patient* front) {
    int search_id;
    cout << "\nEnter Patient ID to search: ";
    cin >> search_id;

    Patient* temp = front;
    while (temp != nullptr) {
        if (temp->id == search_id) {
            cout << "\nPatient Found!" << endl;
            cout << "Name: " << temp->name << " | Age: " << temp->age 
                 << " | Disease: " << temp->disease << " | Priority: " << temp->priority << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "\nPatient ID " << search_id << " not found in the active queue." << endl;
}

void view_history() {
    cout << "\n--- Discharged Patient History ---" << endl;
    ifstream file("history.txt");
    string line;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No history found or file could not be opened." << endl;
    }
}

void staff_dashboard(Patient*& front) {
    int choice = 0;
    do {
        cout << "\n=== STAFF DASHBOARD ===" << endl;
        cout << "1. Intake Patient" << endl;
        cout << "2. View Waiting List" << endl;
        cout << "3. Consult Next Patient" << endl;
        cout << "4. Lookup Patient" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: intake_patient(front); break;
            case 2: waiting_list(front); break;
            case 3: consult_patient(front); break;
            case 4: lookup_patient(front); break;
            case 5: cout << "Logging out..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
}

void admin_dashboard(Patient*& front) {
    int choice = 0;
    do {
        cout << "\n=== ADMIN DASHBOARD ===" << endl;
        cout << "1. Intake Patient" << endl;
        cout << "2. View Waiting List" << endl;
        cout << "3. Consult Next Patient" << endl;
        cout << "4. Lookup Patient" << endl;
        cout << "5. View Consultation History" << endl;
        cout << "6. Logout" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: intake_patient(front); break;
            case 2: waiting_list(front); break;
            case 3: consult_patient(front); break;
            case 4: lookup_patient(front); break;
            case 5: view_history(); break;
            case 6: cout << "Logging out..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
}