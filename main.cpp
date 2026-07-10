#include <iostream>
#include <fstream>
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
const string filename = "students.csv";

void saveStudentsToFile() {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Could not save data to file.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        file << students[i].id << ","
             << students[i].name << ","
             << students[i].age << ","
             << students[i].grade << "\n";
    }

    file.close();
}

void loadStudentsFromFile() {
    ifstream file(filename);

    if (!file.is_open()) {
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        Student s;

        int firstComma = line.find(',');
        int secondComma = line.find(',', firstComma + 1);
        int thirdComma = line.find(',', secondComma + 1);

        s.id = stoi(line.substr(0, firstComma));
        s.name = line.substr(firstComma + 1, secondComma - firstComma - 1);
        s.age = stoi(line.substr(secondComma + 1, thirdComma - secondComma - 1));
        s.grade = stod(line.substr(thirdComma + 1));

        students.push_back(s);
    }

    file.close();
}

void displayMenu() {
    cout << "\n Student Management System \n";
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
    saveStudentsToFile();
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "\nNo students found.\n";
        return;
    }

    cout << "\n Student List \n";
    for (int i = 0; i < students.size(); i++) {
        cout << "ID: " << students[i].id << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Age: " << students[i].age << "\n";
        cout << "Grade: " << students[i].grade << "\n";
        cout << "  \n";
    }
}

void searchStudent() {
    int id;
    cout << "\nEnter student ID to search: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
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

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << "Enter new name: ";
            cin >> students[i].name;

            cout << "Enter new age: ";
            cin >> students[i].age;

            cout << "Enter new grade: ";
            cin >> students[i].grade;

            saveStudentsToFile();
            cout << "Student updated successfully \n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void deleteStudent() {
    int id;
    cout << "\nEnter student ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            saveStudentsToFile();
            cout << "Student deleted successfully \n";
            return;
        }
    }

    cout << "Student not found.\n";
}

int main() {
    int choice;

    loadStudentsFromFile();

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
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid option,try again.\n";
        }
    }

    return 0;
}
