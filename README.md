# 📚 Book Management System in C

A simple menu-based program written in C. It lets the user add books, view the book list, search by title, and update whether a book is available.

## 📌 Project Description

The Book Management System stores each book's title, author, and availability status while the program is running. The user can select an option from the menu to add, view, search, or update book details.

The program uses an array of structures. The book list can hold up to 50 books. The information is kept in memory, so it is cleared when the program is closed.

## ✨ Features

- Add a book with its title and author
- View all books and their availability
- Search for a book by its exact title
- Mark a book as available or not available
- Menu-based program that keeps running until Exit is selected
- Checks for an empty book list and an invalid menu choice

## 💻 Technologies Used

- C Programming Language
- GCC Compiler
- Visual Studio Code

## 📂 Project Structure

```text
Book-Management-System-C/
│
├── book_management.c
└── README.md
```

## ⚙️ Programming Concepts Used

1. Structures
2. Arrays
3. User-defined functions
4. `while` loop
5. `switch-case` statement
6. `if-else` conditions
7. Strings and `strcmp`
8. Input and output with `scanf` and `printf`

## 🚀 How to Run the Project

Open a terminal in the project folder.

### Step 1: Compile the C Program

```bash
gcc book_management.c -o book_management
```

### Step 2: Run the Program

For Windows:

```bash
book_management.exe
```

For Linux/macOS:

```bash
./book_management
```

## 📸 Sample Output

```text
===== Book Management System =====
1. Add a book
2. View all books
3. Search for a book
4. Update availability
5. Exit
Enter your choice: 1
Enter book title: The Alchemist
Enter author name: Paulo Coelho
Book added successfully.
```

## 🎯 Objectives

- To learn how to use structures to keep related book details together.
- To practise arrays and user-defined functions in C.
- To use a menu, loops, and conditions in a small program.
- To build a simple program for managing a book list.

## 🔮 Future Scope

- Save books in a file so the list remains after the program closes.
- Add an option to delete a book.
- Add separate issue and return options.

## 👩‍💻 Student Details

UID: **26BCD10314**

Course: **BCA**

## 🎓 Project Information

Project Type: College Minor Project

Subject: C Programming

Academic Session: 2026

Submitted To: **Kamaldeep Kaur**
# C_Programming_Book_Management
