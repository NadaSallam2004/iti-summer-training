# Library Management System

## Project Overview

This project is a simple Library Management System implemented in C++ to demonstrate Object-Oriented Programming concepts and the use of Smart Pointers for safe memory management.

## Classes

- **Library**: Manages collections of books and users.
- **Book**: Represents a book with attributes such as title, author, and ID.
- **Borrowable**: Abstract interface defining methods for borrowing, returning, and checking availability.
- **User**: Abstract base class inherited by:
  - Student
  - Teacher
  - Engineer

## Relationships

- Library ↔ Book → Composition
- Library ↔ User → Aggregation
- Book ↔ Borrowable → Inheritance
- User ↔ Student/Teacher/Engineer → Inheritance

## Smart Pointers

- **unique_ptr**: Used for books to ensure exclusive ownership by the library.
- **shared_ptr**: Used for users to allow shared ownership across different parts of the system.
- This design prevents issues such as memory leaks and dangling pointers.

## Example Output

## Concepts Applied

- Object-Oriented Programming principles (inheritance, composition, aggregation).
- Smart Pointers (`unique_ptr`, `shared_ptr`).
- Basic exercises with vectors, strings, and templates as part of practice.
