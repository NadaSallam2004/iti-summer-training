#include "Book.h"

void Book::displayBookInfo() {
    cout << "Title: " << title << ", Author: " << author << ", ID: " << bookId << endl;
}

void Book::borrowBook() {
    if (isAvailable) {
        isAvailable = false;
        cout << title << " borrowed successfully.\n";
    }
    else {
        cout << title << " is not available.\n";
    }
}

void Book::returnBook() {
    isAvailable = true;
    cout << title << " returned successfully.\n";
}

bool Book::checkAvailability() {
    return isAvailable;
}