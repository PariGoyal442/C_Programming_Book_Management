#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50
#define TEXT_SIZE 50

/* Each book has a title, an author, and an availability value. */
struct Book
{
    char title[TEXT_SIZE];
    char author[TEXT_SIZE];
    int available; /* 1 means available, 0 means not available */
};

/* Function declarations */
void addBook(struct Book books[], int *bookCount);
void viewBooks(const struct Book books[], int bookCount);
void searchBook(const struct Book books[], int bookCount);
void updateAvailability(struct Book books[], int bookCount);

int main(void)
{
    struct Book books[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    /* Show the menu again after each action. */
    while (1)
    {
        printf("\n===== Book Management System =====\n");
        printf("1. Add a book\n");
        printf("2. View all books\n");
        printf("3. Search for a book\n");
        printf("4. Update availability\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        /* Check that the menu choice is a number. */
        if (scanf("%d", &choice) != 1)
        {
            printf("Please enter a number from 1 to 5.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                addBook(books, &bookCount);
                break;

            case 2:
                viewBooks(books, bookCount);
                break;

            case 3:
                searchBook(books, bookCount);
                break;

            case 4:
                updateAvailability(books, bookCount);
                break;

            case 5:
                printf("Program closed.\n");
                return 0;

            default:
                printf("Please choose an option from 1 to 5.\n");
        }
    }
}

/* Read a book's details and add it to the array. */
void addBook(struct Book books[], int *bookCount)
{
    if (*bookCount == MAX_BOOKS)
    {
        printf("The book list is full.\n");
        return;
    }

    printf("Enter book title: ");
    /* The space before %49 skips the Enter key left by the menu input. */
    if (scanf(" %49[^\n]", books[*bookCount].title) != 1)
    {
        printf("Could not read the title. Please try again.\n");
        return;
    }

    printf("Enter author name: ");
    if (scanf(" %49[^\n]", books[*bookCount].author) != 1)
    {
        printf("Could not read the author name. Please try again.\n");
        return;
    }

    /* New books are available when they are first added. */
    books[*bookCount].available = 1;
    *bookCount = *bookCount + 1;

    printf("Book added successfully.\n");
}

/* Print every book that has been added. */
void viewBooks(const struct Book books[], int bookCount)
{
    int i;

    if (bookCount == 0)
    {
        printf("No books have been added yet.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    for (i = 0; i < bookCount; i++)
    {
        printf("%d. Title: %s\n", i + 1, books[i].title);
        printf("   Author: %s\n", books[i].author);

        if (books[i].available == 1)
        {
            printf("   Status: Available\n");
        }
        else
        {
            printf("   Status: Not available\n");
        }
    }
}

/* Find and display a book by its exact title. */
void searchBook(const struct Book books[], int bookCount)
{
    char titleToFind[TEXT_SIZE];
    int i;

    if (bookCount == 0)
    {
        printf("No books are available to search.\n");
        return;
    }

    printf("Enter the exact book title: ");
    if (scanf(" %49[^\n]", titleToFind) != 1)
    {
        printf("Could not read the title. Please try again.\n");
        return;
    }

    for (i = 0; i < bookCount; i++)
    {
        if (strcmp(books[i].title, titleToFind) == 0)
        {
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);

            if (books[i].available == 1)
            {
                printf("Status: Available\n");
            }
            else
            {
                printf("Status: Not available\n");
            }
            return;
        }
    }

    printf("Book not found. Check the title and try again.\n");
}

/* Change a book's status to available or not available. */
void updateAvailability(struct Book books[], int bookCount)
{
    char titleToFind[TEXT_SIZE];
    int newStatus;
    int i;

    if (bookCount == 0)
    {
        printf("No books are available to update.\n");
        return;
    }

    printf("Enter the exact book title: ");
    if (scanf(" %49[^\n]", titleToFind) != 1)
    {
        printf("Could not read the title. Please try again.\n");
        return;
    }

    for (i = 0; i < bookCount; i++)
    {
        if (strcmp(books[i].title, titleToFind) == 0)
        {
            printf("1. Available\n");
            printf("2. Not available\n");
            printf("Choose the new status: ");

            if (scanf("%d", &newStatus) != 1 ||
                (newStatus != 1 && newStatus != 2))
            {
                printf("Please enter 1 or 2.\n");
                return;
            }

            if (newStatus == 1)
            {
                books[i].available = 1;
            }
            else
            {
                books[i].available = 0;
            }

            printf("Book status updated.\n");
            return;
        }
    }

    printf("Book not found. Check the title and try again.\n");
}