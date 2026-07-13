#include <iostream>
#include <string>
using namespace std;

double getPositiveDouble(string message) {
    double value;
    do {
        cout << message;
        cin >> value;
        if (value < 0)
            cout << "Invalid input! Please enter a positive number.\n";
    } while (value < 0);
    return value;
}

string getValidPosition() {
    string pos;
    do {
        cout << "Position (m = manager, e = employee): ";
        cin >> pos;
        if (!(pos == "m" || pos == "M" || pos == "e" || pos == "E"))
            cout << "Invalid position. Enter m or e.\n";
    } while (!(pos == "m" || pos == "M" || pos == "e" || pos == "E"));
    return pos;
}

double calculateSalary(int hrs, double rate) {
    return hrs * rate;
}

double calculateSalary(int hrs, double rate, double overtime) {
    return (hrs * rate) + (overtime * rate * 1.5);
}

void displayPayroll(string name, int id, double salary, double tax) {
    cout << "\n================PayRoll================\n";
    cout << "Employee: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "TAX: " << tax << " $" << endl;
    cout << "Final Salary: " << salary - tax << " $" << endl;
}

int main() {
    string name, position;
    int id, hrs;
    double rate, overtime = 0, salary, tax;

    cout << "Employee name: ";
    cin >> name;
    cout << "Employee ID: ";
    cin >> id;
    hrs = getPositiveDouble("Working Hrs: ");
    rate = getPositiveDouble("Hourly Rate: ");
    position = getValidPosition();

    if (position == "m" || position == "M") {
        overtime = getPositiveDouble("OverTime hrs: ");
        salary = calculateSalary(hrs, rate, overtime);
    }
    else {
        salary = calculateSalary(hrs, rate);
    }

    cout << "\nSalary before TAX: " << salary << " $" << endl;

    char addBonus;
    cout << "Add Bonus? (y/n): ";
    cin >> addBonus;
    if (addBonus == 'y' || addBonus == 'Y') {
        salary += 50;
        cout << "Bonus added.\n";
    }

    tax = 0.107 * salary;
    displayPayroll(name, id, salary, tax);

    return 0;
}




