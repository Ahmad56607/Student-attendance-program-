#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int rollN;
    bool present;
};

vector<Student> students;

void save(const vector<Student>& students, const string& filePath) {
   ofstream out("C:/Muhammad Ahmad/student_attendance_program_File.txt");
    if (!out) {
        cout << "File not found: " << filePath << endl;
        return;
    }
    for (const auto& student : students) {
        out << "Name: " << student.name << endl;
        out << "Roll No: " << student.rollN << endl;
        out << "Status: " << (student.present ? "Present" : "Absent") << endl << endl;
    }
    out.close();
    cout << "Saved to file: " << filePath << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Take Attendance" << endl;
        cout << "3. Show Details" << endl;
        cout << "4. Save to File" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            char continueChoice;
            do {
                Student student;
                cout << "Enter Name: ";
                cin >> student.name;
                cout << "Enter Roll No: ";
                cin >> student.rollN;
                student.present = false; 
                students.push_back(student);
                cout << "Student added." << endl;
                cout << "Enter 'x' to exit or 'c' to continue: ";
                cin >> continueChoice;
            } while (continueChoice != 'x' && continueChoice == 'c');
        } else if (choice == 2) {
            system("cls");
            char attendanceChoice;
            for (auto& student : students) {
                cout << "Name: " << student.name << endl;
                cout << "Roll No: " << student.rollN << endl;
                cout << "Enter 'p' for present or 'o' for absent: ";
                cin >> attendanceChoice;
                student.present = (attendanceChoice == 'p');
            }
        } else if (choice == 3) {
            system("cls");
            for (const auto& student : students) {
                cout << "Name: " << student.name << endl;
                cout << "Roll No: " << student.rollN << endl;
                cout << "Status: " << (student.present ? "Present" : "Absent") << endl << endl;
            }
        } else if (choice == 4) {
            save(students, "C:/Muhammad Ahmad/student_attendance_program_File.txt");
        } else if (choice == 0) {
            exit(0);
        } else {
            system("cls");
            cout << "Invalid input." << endl;
        }
    }
}