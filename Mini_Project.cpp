#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float attendance, unitTest, achievements, mockPractical;
    float totalScore;

public:
    static float attendanceOutOf, unitTestOutOf, achievementsOutOf, mockPracticalOutOf;

    void inputDetails();
    void calculateAssessment();
    void displayReportRow();
    int getRollNo() { return rollNo; }
};

// Static members initialization
float Student::attendanceOutOf = 10;
float Student::unitTestOutOf = 30;
float Student::achievementsOutOf = 10;
float Student::mockPracticalOutOf = 50;

void Student::inputDetails() {
    cout << "\nEnter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> rollNo;

    cout << "\nNow Enter Student's Scores:\n";
    cout << "Attendance Marks: ";
    cin >> attendance;
    cout << "Unit Test Marks: ";
    cin >> unitTest;
    cout << "Achievements Marks: ";
    cin >> achievements;
    cout << "Mock Practicals Marks: ";
    cin >> mockPractical;

    calculateAssessment();
}

void Student::calculateAssessment() {
    totalScore = attendance + unitTest + achievements + mockPractical;
}

void Student::displayReportRow() {
    stringstream attStr, unitStr, achStr, mockStr;

    attStr << fixed << setprecision(1) << attendance << "/" << attendanceOutOf;
    unitStr << fixed << setprecision(1) << unitTest << "/" << unitTestOutOf;
    achStr << fixed << setprecision(1) << achievements << "/" << achievementsOutOf;
    mockStr << fixed << setprecision(1) << mockPractical << "/" << mockPracticalOutOf;

    cout << left << setw(17) << name
         << setw(10) << rollNo
         << setw(10) << fixed << setprecision(1) << totalScore
         << setw(15) << attStr.str()
         << setw(15) << unitStr.str()
         << setw(17) << achStr.str()
         << setw(18) << mockStr.str()
         << "\n";
}

void displayTableHeader() {
    cout << "\n" << left
         << setw(15) << "Name"
         << setw(10) << "RollNo"
         << setw(10) << "Total"
         << setw(15) << "Attendance"
         << setw(15) << "Unit Test"
         << setw(17) << "Achievements"
         << setw(18) << "Mock Practicals" << "\n";
    cout << string(100, '-') << "\n";
}

void displayMenu() {
    cout << "\n\n========== Student Assessment System ==========\n";
    cout << "1. Add New Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student by Roll No\n";
    cout << "4. Delete Student\n";
    cout << "5. Exit\n";
    cout << "==============================================\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<Student> students;
    int choice;

    // Input 'out of' values once
    cout << "Enter Outof field for Assessment:\n";
    cout << "Attendance Marks: ";
    cin >> Student::attendanceOutOf;
    cout << "Unit Test Marks: ";
    cin >> Student::unitTestOutOf;
    cout << "Achievements Marks: ";
    cin >> Student::achievementsOutOf;
    cout << "Mock Practicals Marks: ";
    cin >> Student::mockPracticalOutOf;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                Student s;
                s.inputDetails();
                students.push_back(s);
                break;
            }
            case 2: {
                if (students.empty()) {
                    cout << "No student records found.\n";
                } else {
                    displayTableHeader();
                    for (auto& s : students) {
                        s.displayReportRow();
                    }
                }
                break;
            }
            case 3: {
                int roll;
                cout << "Enter Roll Number to Search: ";
                cin >> roll;
                bool found = false;
                for (auto& s : students) {
                    if (s.getRollNo() == roll) {
                        displayTableHeader();
                        s.displayReportRow();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student with Roll No " << roll << " not found.\n";
                }
                break;
            }
            case 4: {
                int roll;
                cout << "Enter Roll Number to Delete: ";
                cin >> roll;
                auto it = remove_if(students.begin(), students.end(), [roll](Student& s) {
                    return s.getRollNo() == roll;
                });
                if (it != students.end()) {
                    students.erase(it, students.end());
                    cout << "Student with Roll No " << roll << " has been deleted.\n";
                } else {
                    cout << "Student with Roll No " << roll << " not found.\n";
                }
                break;
            }
            case 5:
                cout << "Thank you for using the system.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
