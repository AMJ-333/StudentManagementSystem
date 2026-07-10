#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    double grade;
};

vector<Student> students;

void displayMenu() {
    cout << "\n===== Student Management System =====\n";
    cout << "1. Add Student\n";
    cout << "2. View All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

void addStudent() {
    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    cout << "Enter Student Name: ";
    cin >> s.name;

    cout << "Enter Student Age: ";
    cin >> s.age;

    cout << "Enter Student Grade: ";
    cin >> s.grade;

    students.push_back(s);
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "\nNo students found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << "ID: " << students[i].id << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Age: " << students[i].age << "\n";
        cout << "Grade: " << students[i].grade << "\n";
        cout << "--------------------\n";
    }
}

void searchStudent() {
    int id;
    cout << "\nEnter student ID to search: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << "\nStudent found!\n";
            cout << "ID: " << students[i].id << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Age: " << students[i].age << "\n";
            cout << "Grade: " << students[i].grade << "\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void updateStudent() {
    int id;
    cout << "\nEnter student ID to update: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << "Enter new name: ";
            cin >> students[i].name;

            cout << "Enter new age: ";
            cin >> students[i].age;

            cout << "Enter new grade: ";
            cin >> students[i].grade;

            cout << "Student updated successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void deleteStudent() {
    int id;
    cout << "\nEnter student ID to delete: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

int main() {
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
