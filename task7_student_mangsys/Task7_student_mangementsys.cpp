#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student {
private:
    string name;
    int id;
    double grade;

public:
    Student(string n, int i, double g = 0.0) {
        name = n;
        id = i;
        grade = g;
    }

    string getName() const {
        return name; 
    }
    int getId() const { 
        return id; 
    }
    double getGrade() const {
        return grade;
    }
    void setGrade(double g) {
        grade = g;
    }
    void display() const {
        cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << endl;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
        cout << "Student added successfully!\n";
    }

    void showAllStudents() const {
        if (students.empty()) {
            cout << "No students available!\n";
            return;
        }
        cout << "\n--- All Students ---\n";
        for (auto& s : students) s.display();
    }

    void searchStudent(int id) const {
        for (auto& s : students) {
            if (s.getId() == id) {
                cout << "Student found:\n";
                s.display();
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void updateGrade(int id, double newGrade) {
        for (auto& s : students) {
            if (s.getId() == id) {
                s.setGrade(newGrade);
                cout << "Grade updated successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void deleteStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                students.erase(it);
                cout << "Student deleted successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Grade\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name; int id; double grade;
            cout << "Enter name, ID, grade: ";
            cin >> name >> id >> grade;
            sms.addStudent(Student(name, id, grade));
        }
        else if (choice == 2) {
            sms.showAllStudents();
        }
        else if (choice == 3) {
            int id; cout << "Enter ID: "; cin >> id;
            sms.searchStudent(id);
        }
        else if (choice == 4) {
            int id; double grade;
            cout << "Enter ID and new grade: ";
            cin >> id >> grade;
            sms.updateGrade(id, grade);
        }
        else if (choice == 5) {
            int id; cout << "Enter ID: "; cin >> id;
            sms.deleteStudent(id);
        }
    } while (choice != 0);

    cout << "Exiting system...\n";
    return 0;
}

