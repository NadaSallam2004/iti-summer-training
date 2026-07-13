#include <iostream>
#include "bank.h"
using namespace std;

double balance = 0;

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
