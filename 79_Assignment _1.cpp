// library management system
#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;

class Book 
{
public:
    string title;
    string author;
    int year;

    Book() {}

    Book(string t, string a, int y) : title(t), author(a), year(y) {}
};

class Library 
{
private:
    Book books[MAX_BOOKS];
    int numBooks;

public:
    Library() : numBooks(0) {}

    void displayBooks() 
	{
        if (numBooks == 0) 
		{
            cout << "Library is empty." << endl;
            return;
        }

        cout << "Library Books:" << endl;
        for (int i = 0; i < numBooks; ++i) 
		{
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
        }
    }

    void insertBook(string title, string author, int year) 
	{
        if (numBooks < MAX_BOOKS) 
		{
            books[numBooks++] = Book(title, author, year);
            cout << "Book added successfully." << endl;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    void updateBook(int index, string title, string author, int year) {
        if (index >= 0 && index < numBooks) {
            books[index] = Book(title, author, year);
            cout << "Book updated successfully." << endl;
        } else {
            cout << "Invalid book index." << endl;
        }
    }

    void deleteBook(int index) 
	{
        if (index >= 0 && index < numBooks) 
		{
            for (int i = index; i < numBooks - 1; ++i) 
			{
                books[i] = books[i + 1];
            }
            numBooks--;
            cout << "Book deleted successfully." << endl;
        } else 
		{
            cout << "Invalid book index." << endl;
        }
    }
};

int main() 
{
    Library library;
    int choice;

    do 
	{
        cout << "Library Management System Menu:" << endl;
        cout << "1. Display Books" << endl;
        cout << "2. Insert Book" << endl;
        cout << "3. Update Book" << endl;
        cout << "4. Delete Book" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                library.displayBooks();
                break;
                
            case 2: 
			{
                string title, author;
                int year;
                cout << "Enter book title: ";
                cin >> title;
                cout << "Enter author: ";
                cin >> author;
                cout << "Enter year: ";
                cin >> year;
                library.insertBook(title, author, year);
                break;
            }
            case 3: 
			{
                int index;
                string title, author;
                int year;
                cout << ("Enter the index of the book to update: ");
                cin >> index;
                cout << "Enter new book title: ";
                cin >> title;
                cout << "Enter new author: ";
                cin >> author;
                cout << "Enter new year: ";
                cin >> year;
                library.updateBook(index, title, author, year);
                break;
            }
            case 4: 
			{
                int index;
                cout << "Enter the index of the book to delete: ";
                cin >> index;
                library.deleteBook(index);
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

