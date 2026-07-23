#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include "Borrowable.h"
using namespace std;

class Book : public Borrowable {
private:
    string title;
    string author;
    int bookId;
    bool isAvailable;

public:
    Book(string t, string a, int id) : title(t), author(a), bookId(id), isAvailable(true) {}

    void displayBookInfo();
    void borrowBook() override;
    void returnBook() override;
    bool checkAvailability() override;
};

#endif
