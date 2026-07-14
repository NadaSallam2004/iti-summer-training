#include <iostream>
#include <string>
using namespace std;
void inputMarks(int* math, int* physics, int* english) {
    cout << "Enter Math mark: ";
    cin >> *math;
    cout << "Enter Physics mark: ";
    cin >> *physics;
    cout << "Enter English mark: ";
    cin >> *english;
}
double calculateAverage(int* math, int* physics, int* english) {
    return (*math + *physics + *english) / 3.0;
}
char calculateGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}
void printReport(string name, int* math, int* physics, int* english) {
    double avg = calculateAverage(math, physics, english);
    char grade = calculateGrade(avg);
    cout << "\nStudent: " << name << endl;
    cout << "Math    : " << *math << endl;
    cout << "Physics : " << *physics << endl;
    cout << "English : " << *english << endl;
    cout << "Average : " << avg << endl;
    cout << "Grade   : " << grade << endl;
}
int main() {
    string name;
    int math, physics, english;
    int choice;
    cout << "Enter student name: ";
    getline(cin, name);
    inputMarks(&math, &physics, &english);
    do {
        cout << "\nMenu:\n";
        cout << "1. Update a mark\n";
        cout << "2. Recalculate average\n";
        cout << "3. Print report\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            inputMarks(&math, &physics, &english);
            break;
        case 2:
            cout << "Average: " << calculateAverage(&math, &physics, &english) << endl;
            break;
        case 3:
            printReport(name, &math, &physics, &english);
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}

