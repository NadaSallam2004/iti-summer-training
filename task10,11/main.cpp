#include "Library.h"
#include "Book.h"
#include "User.h"
#include <memory>

int main() {
    Library lib;

    lib.addBook(make_unique<Book>("C++ Basics", "Nada", 101));
    lib.addBook(make_unique<Book>("OOP Concepts", "Ahmed", 102));

    lib.addUser(make_shared<Student>("Ali", 1));
    lib.addUser(make_shared<Teacher>("Sara", 2));
    lib.addUser(make_shared<Engineer>("Omar", 3));

    lib.displayBooks();

    return 0;
}