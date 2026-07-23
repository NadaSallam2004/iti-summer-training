#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<std::unique_ptr<Book>> books;   // „·ﬂÌ… Õ’—Ì… ··ﬂ »
    std::vector<std::shared_ptr<User>> users;   // „·ﬂÌ… „‘ —ﬂ… ··„” Œœ„Ì‰

public:
    void addBook(std::unique_ptr<Book> b);
    void addUser(std::shared_ptr<User> u);
    void displayBooks();
};

#endif
