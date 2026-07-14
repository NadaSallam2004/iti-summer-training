#include <iostream>
using namespace std;

void increment(int* num) {
    (*num)++;
}
void decrement(int* num) {
    (*num)--;
}
void reset(int* num) {
    *num = 0;
}
void printNumber(int* num) {
    cout << "Current Number = " << *num << endl;
}
int main() {
    int number;
    cout << "Enter number: ";
    cin >> number;

    int choice;
    do {
        cout << "\n1. Increment\n2. Decrement\n3. Reset\n4. Show Number\n5. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            increment(&number);
            printNumber(&number);
            break;
        case 2:
            decrement(&number);
            printNumber(&number);
            break;
        case 3:
            reset(&number);
            printNumber(&number);
            break;
        case 4:
            printNumber(&number);
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);
    return 0;
}

