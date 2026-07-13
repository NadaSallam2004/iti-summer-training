#include <iostream>
#include "menu.h"
#include "bank.h"
using namespace std;

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
