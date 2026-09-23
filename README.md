# DSA_mini_project
# Hospital Patient Management System

> **Team members** --> **`Priya`**, **`Pratistha`**, **`Rabit`**, **`Rajkumar`**.

> Everyone is open to giving **suggestions** on this project to make it more useful.

> Everyone must **pull** the code from the origin to your local machine before writing a single line of code. You must **push** your code after completing your work for a better experience and to **not fall into the web of ~~ERRORS~~**.

> Make sure that when you commit the code, the commit message contains the real meaning of your work—meaning what you changed and modified in the repo.

---

## 📖 Project Overview

The **Hospital Patient Management System** is a robust, C++ terminal-based application designed to digitally manage a hospital's triage and consultation workflow. 

Instead of relying on built-in C++ libraries (like `<queue>`), this project utilizes a **custom Linked List Data Structure** to function as a Priority Queue. This ensures that when a new patient arrives, they are dynamically sorted into the queue based on their medical urgency rather than their arrival time. Emergency patients will automatically bypass standard patients to receive immediate care. 

The system features Role-Based Access Control (RBAC), automated consultation timers simulating doctor availability, and file-handling to permanently archive discharged patients.

---

## 🔐 System Login Credentials

The system is protected by Role-Based Access Control. You must use one of the following credentials to access the dashboards.

| Role | Username | Password | Access Level |
|---|---|---|---|
| **Staff (Tier-1)** | `staff` | `staff123` | Can intake patients, view the waiting list, and run consultations. |
| **Admin (Tier-2)** | `admin` | `admin123` | Has all Staff permissions, plus access to the external `history.txt` archive. |

---

## 🛠️ User Guide: How to Use the System

Follow these steps to navigate the terminal interface once the program is running:

### Step 1: Login
Upon launching the program, you will be prompted to log in. Enter the Username and Password from the credentials table above. Your input determines whether you see the Staff Dashboard or the Admin Dashboard.

### Step 2: Register a New Patient (Intake)
1. Select **Option 1 (Intake Patient)** from the main menu.
2. The system will prompt you for the patient's ID, Name, Age, and Disease.
3. Enter the **Priority Level** as an integer. 
   * *Example: `1` for Life-threatening Emergency, `2` for High Priority, `3` for Standard Checkup.*
4. The system will automatically insert the patient into the correct spot in the waiting line based on the priority number.

### Step 3: View the Waiting List
Select **Option 2 (View Waiting List)**. The terminal will print a live view of the queue, ordered strictly by priority. The patient at the very top is the next to see the doctor.

### Step 4: Consult & Discharge
1. Select **Option 3 (Consult Next Patient)**.
2. The system will automatically call the patient at the front of the line (highest priority).
3. A **30-second automated timer** will begin, simulating the medical consultation. A loading bar will appear in the terminal.
4. Once the timer finishes, the patient is removed from the active queue and their data is permanently saved to `history.txt`. 

### Step 5: Lookup a Patient
Select **Option 4 (Lookup Patient)**. Enter a Patient ID to instantly search the active queue. The system will display their name, condition, and current priority status.

### Step 6: View History (Admin Only)
If logged in as `admin`, select **Option 5 (View Consultation History)**. The system will open the external `history.txt` file and print a record of every patient who has been successfully consulted and discharged.

---

## ⚙️ Core Functional Requirements

- [x] **User Authentication:** Restricts basic access to authorized staff.
- [x] **Patient Intake:** Registers incoming patients using a custom `Patient` struct.
- [x] **Priority Queue Management:** Dynamically sorts waiting patients in real-time by medical priority via a linked list.
- [x] **Consultation Dispatch:** Calls the next highest-priority patient at the front of the line.
- [x] **Patient Lookup:** Fast search by `Patient ID` to retrieve patient status.
- [x] **Discharge / Queue Removal:** Deregisters and removes a patient from active memory (RAM) once consultation is complete.
- [x] **Queue Inspection:** Views an overview of all active, waiting patients at any time.

---

## 💻 Developer Guide: How to Compile and Run

To run this project on your local machine, ensure you have a C++ compiler installed (like GCC/`g++`). Both `main.cpp` and `essential.h` must be located in the same folder.

1. Open your terminal and navigate to the project directory.
2. Compile the code using the following command:
   ```bash
   g++ main.cpp -o hospital_system