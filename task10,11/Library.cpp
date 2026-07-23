#include "Library.h"
#include <iostream>
using namespace std;

void Library::addBook(unique_ptr<Book> b) {
    books.push_back(move(b));
}

void Library::addUser(shared_ptr<User> u) {
    users.push_back(u);
}

void Library::displayBooks() {
    for (auto& b : books)
        b->displayBookInfo();
}