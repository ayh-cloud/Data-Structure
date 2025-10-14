#include <iostream>
#include "Book.h"
#include "DoubleLinkedList.h"

using namespace std;

int main() {
    DoubleLinkedList link;
    int choice;
    do {
        cout << "\t\t\t~LIBRARY MENU~" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book By Position" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Borrow Book" << endl;
        cout << "5. Sort Book By Title" << endl;
        cout << "6. Show Statistics" << endl;
        cout << "7. Print Books" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string title, author, genre;
                int ISBN;
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                cin >> ISBN;
                cin.ignore();
                cout << "Enter Genre: ";
                getline(cin, genre);
                Book b(title, author, ISBN, genre, true);
                link.insertRight(b);
                cout << "Book Added Successfully!!!" << endl;
                break;
            }
            case 2: {
                int position;
                cout << "Enter Position To Remove: ";
                cin >> position;
                link.removeAtPosition(position);
                cout << "Book Removed Successfully!!!" << endl;
                break;
            }
            case 3: {
                string key, value;
                cout << "Search By (title, author, genre, ISBN): ";
                cin >> key;
                cin.ignore();
                cout << "Enter Value: ";
                getline(cin, value);
                link.searchBook(key, value);
                break;
            }
            case 4: {
                int ISBN;
                cout << "Enter ISBN To Borrow: ";
                cin >> ISBN;
                link.borrowBook(ISBN);
                break;
            }
            case 5:
                link.sort();
                cout << "Books Sorted Successfully!!!" << endl;
                break;
            case 6:
                link.showStatistics();
                break;
            case 7:
                link.print();
                break;
            case 8:
                cout << "Exiting Program....." << endl;
                break;
            default:
                cout << "Invalid Choice! Please Try Again...." << endl;
        }

    } while (choice != 8);

    return 0;
}
