#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string id;
    int year;
    string department;
    int bedNo;
    int chairNo;
    int roomNo;
    Student* next;
};

Student* head = NULL;

int countStudentsInRoom(int room) {
    Student* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp->roomNo == room)
            count++;
        temp = temp->next;
    }
    return count;
}

void addStudent() {
    int room;
    cout << "Enter Room Number: ";
    cin >> room;

    if (countStudentsInRoom(room) >= 4) {
        cout << "Room already has 4 students!\n";
        return;
    }

    Student* newStudent = new Student;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newStudent->name);

    cout << "Enter ID: ";
    getline(cin, newStudent->id);

    cout << "Enter Year: ";
    cin >> newStudent->year;
    cin.ignore();

    cout << "Enter Department: ";
    getline(cin, newStudent->department);

    cout << "Enter Bed Number: ";
    cin >> newStudent->bedNo;

    cout << "Enter Chair Number: ";
    cin >> newStudent->chairNo;

    newStudent->roomNo = room;
    newStudent->next = head;
    head = newStudent;

    cout << "Student added successfully!\n";
}

void displayStudents() {
    Student* temp = head;
    if (temp == NULL) {
        cout << "No students recorded.\n";
        return;
    }

    while (temp != NULL) {
        cout << "\nName: " << temp->name;
        cout << "\nID: " << temp->id;
        cout << "\nYear: " << temp->year;
        cout << "\nDepartment: " << temp->department;
        cout << "\nRoom Number: " << temp->roomNo;
        cout << "\nBed Number: " << temp->bedNo;
        cout << "\nChair Number: " << temp->chairNo;
        cout << "\n---------------------------\n";
        temp = temp->next;
    }
}

void deleteStudent() {
    string id;
    cout << "Enter ID to delete: ";
    cin.ignore();
    getline(cin, id);

    Student* temp = head;
    Student* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Student not found.\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Student deleted successfully.\n";
}

void updateStudent() {
    string id;
    cout << "Enter ID to update: ";
    cin.ignore();
    getline(cin, id);

    Student* temp = head;

    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Enter New Name: ";
    getline(cin, temp->name);

    cout << "Enter New Year: ";
    cin >> temp->year;
    cin.ignore();

    cout << "Enter New Department: ";
    getline(cin, temp->department);

    cout << "Student updated successfully!\n";
}

int main() {
    int choice;
    do {
        cout << "\nDormitory Management System";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Update Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
