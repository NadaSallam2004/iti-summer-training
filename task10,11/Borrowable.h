#ifndef BORROWABLE_H
#define BORROWABLE_H

class Borrowable {
public:
    virtual void borrowBook() = 0;
    virtual void returnBook() = 0;
    virtual bool checkAvailability() = 0;
};

#endif
