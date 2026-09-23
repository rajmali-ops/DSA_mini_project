# Hospital Patient Management System
>Team members --> **`Priya`**, **`Pratistha`**,**`Rabit`**,**`Rajkumar`**.

>Every one is open to give **suggestion** on this project for make it more usefull.

> Every one must be **pull** the code from origin to your local machine before writing a single code.and must be **push** there code after complete your work, for better experience and **not fall into the web of ~~ERRORS~~**.

> Every one make sure, when you commit the code the commit message is contain real meaning of your work, mean what you change and modify in a repo.
---

## 📌 Problem Statement

**A hospital receives patients with different levels of medical urgency. Emergency patients must be attended before normal patients. Develop a Patient Management System using an appropriate data structure.**
- Authenticate the user before accessing the system.
- Add a new patient with patient ID, name, age, disease, and priority.
- Display the waiting list according to priority.
- Call the next patient based on priority.
- Search patient details using Patient ID.
- Remove a patient after consultation.
- Display all waiting patients.

---

## ⚙️ Core Functional Requirements

- [ ] **User Authentication:** Restrict basic access to authorized intake staff before allowing interaction with the system.
- [ ] **Patient Intake:** Register incoming patients with the following schema:
  - `Patient ID` (Unique Identifier)
  - `Name`
  - `Age`
  - `Condition / Disease`
  - `Priority Level` (Emergency vs. Standard / Tiered urgency)
- [ ] **Priority Queue Management:** Display waiting patients sorted in real time by medical priority.
- [ ] **Consultation Dispatch:** Call and serve the next highest-priority patient in the queue.
- [ ] **Patient Lookup:** Fast search by `Patient ID` to retrieve patient status and details.
- [ ] **Discharge / Queue Removal:** Deregister and remove a patient from the active list once consultation is complete.
- [ ] **Queue Inspection:** View an overview of all active, waiting patients at any time.

---

## 🚀 Extended Features

### 1 Automated Consultation Timer
* Implement an automated **30-second consultation timer** per patient.
* Automatically transition the consultation status and call the next queued patient once the duration elapses.

### 2. Archival & History Persistence
* Store all historical consultations and discharged patient data externally (e.g., `.json` or `.txt` storage).
* Maintain complete records without cluttering active in-memory queue states.

### 3. Role-Based Access Control (RBAC)
* **Tier 1 (General Staff):** Intake entry, live queue display, and lookup.
* **Tier 2 (Admin / Senior Staff):** Protected access to previous records and archives via dedicated administrative credentials.

---

## 🧑‍💻 Back-end or Logic
> **Build our own header file** which is containing function which is help us to build this project more convenient, `essential.h` is header file, all functions will be write in header file.

> `main.cpp` is core file mean a entry point of this project.

### Functions:
> This is function section in this section we decide role (who write which function), and how many functions are required.if you want to write a certain function so simply change the empty with your name. 
- [`name of candidate`] `Function name`, requirement.
- [`empty`] `authentication` --> This function is take user-id and password from user,if both are correct so dashboard is open otherwise show 'wrong password and user-id' Re-try, Also manage tier-1 (general staff) and tier-2 (admin and senior staff) users by polymorphism.
- [`empty`] `intake_patient` --> ask patient information and add it in a priority queue (Dynamically)
- [`empty`] `waiting_list` ---> show patient list accordingly to its priority.
- [`empty`] `consult_patient` --> consult with current patient after 30 min this patient is despatch (remove in queue) and call next patient.
- [`empty`] `lookup_patient` --> Check patient information with patient ID.
- 