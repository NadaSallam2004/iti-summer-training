#include <iostream>
using namespace std;

double balance = 0;

void showMenu() {
    cout << "\n===== ATM Menu =====\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
}

void checkBalance() {
    cout << "Your current balance is: " << balance << endl;
}

void deposit(double amount) {
    balance += amount;
    cout << "Deposit successful! New balance: " << balance << endl;
}

void withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful! New balance: " << balance << endl;
    }
    else {
        cout << "Insufficient balance!\n";
    }
}

int main() {
    int choice;
    double amount;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            checkBalance();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            withdraw(amount);
            break;
        case 4:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
