#include <iostream>
#include "essential.h" 

using namespace std;

int main() {
    Patient* front = nullptr;
    int role = 0;

    cout << "Welcome to the Hospital Patient Management System" << endl;

    while (true) {
        role = authentication();
        
        if (role == 1) {
            staff_dashboard(front);
        } else if (role == 2) {
            admin_dashboard(front);
        }
    }

    return 0;
}