#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

class StudentRecordSystem {
private:
    vector<Student> students;

public:
    void addStudent(const string& name, int age, double gpa) {
        Student newStudent;
        newStudent.name = name;
        newStudent.age = age;
        newStudent.gpa = gpa;
        students.push_back(newStudent);
        cout << "Student added successfully!" << endl;
    }

    void viewStudents() {
        if (students.empty()) {
            cout << "No student records available." << endl;
        } else {
            cout << "Student Records:" << endl;
            for (size_t i = 0; i < students.size(); ++i) {
                cout << "[" << i + 1 << "] ";
                cout << "Name: " << students[i].name << ", ";
                cout << "Age: " << students[i].age << ", ";
                cout << "GPA: " << students[i].gpa << endl;
            }
        }
    }

    double calculateAverageGPA() {
        if (students.empty()) {
            cout << "No students to calculate average GPA." << endl;
            return 0.0;
        }

        double totalGPA = 0.0;
        for (const auto& student : students) {
            totalGPA += student.gpa;
        }

        return totalGPA / students.size();
    }
};

int main() {
    StudentRecordSystem recordSystem;
    int choice;

    do {
        cout << "\nStudent Record System\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Calculate Average GPA\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string name;
                    int age;
                    double gpa;

                    cout << "Enter student name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter student age: ";
                    cin >> age;

                    cout << "Enter student GPA: ";
                    cin >> gpa;

                    recordSystem.addStudent(name, age, gpa);
                }
                break;
            case 2:
                recordSystem.viewStudents();
                break;
            case 3:
                cout << "Average GPA: " << recordSystem.calculateAverageGPA() << endl;
                break;
            case 4:
                cout << "Exiting program. Goodbye!";
                break;
            default:
                cout << "Invalid choice. Try again.";
                break;
        }

    } while (choice != 4);

    return 0;
}
