#include "essential.h"

using namespace std;

int main()
{
    cout << "=== HOSPITAL PATIENT MANAGEMENT SYSTEM ===" << endl;

    if (!authentication())
    {
        cout << "Access denied." << endl;
        return 0;
    }

    int choice;

    while (true)
    {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. View Waiting List" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            intake_patient();
        }
        else if (choice == 2)
        {
            waiting_list();
        }
        else if (choice == 3)
        {
            cout << "Program closed." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
