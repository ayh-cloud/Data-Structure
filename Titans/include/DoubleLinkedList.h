#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include "Book.h"

using namespace std;

struct Node {
    Book item;
    Node* next;
    Node* prevece;
};

class Iterator {
private:
    Node* current;

public:
    Iterator(Node* ptr = NULL)
     {
         current=ptr;
     }

    Book getItem() {
        if (current != NULL)
            return current->item;
        return Book();
    }

    Iterator next() {
        if (current != NULL)
            return Iterator(current->next);
        return Iterator(NULL);
    }

    Iterator prev() {
        if (current != NULL)
            return Iterator(current->prevece);
        return Iterator(NULL);
    }

    bool isNull() {
        return current == NULL;
    }

    virtual ~Iterator() {}
};

class DoubleLinkedList {
private:
    Node* right;
    Node* left;
    int length;

public:
    DoubleLinkedList()
    {
        right=NULL;
        left=NULL;
        length=0;
    }


    virtual ~DoubleLinkedList() {
        while (length > 0) {
            removeLeft();
        }
    }

    void insertRight(Book value) {
        Node* newNode = new Node;
        newNode->item = value;
        newNode->next = NULL;
        if (length == 0) {
            right = left = newNode;
            newNode->prevece = NULL;
        } else {
            right->next = newNode;
            newNode->prevece = right;
            right = newNode;
        }
        length++;
    }

    void insertLeft(Book value) {
        Node* newNode = new Node;
        newNode->item = value;
        newNode->prevece = NULL;
        if (length == 0) {
            right = left = newNode;
            newNode->next = NULL;
        } else {
            left->prevece = newNode;
            newNode->next = left;
            left = newNode;
        }
        length++;
    }

    void insertAtPosition(Book value, int position) {
        if (position <= 0) {
            insertLeft(value);
        } else if (position >= length) {
            insertRight(value);
        } else {
            Node* newNode = new Node;
            newNode->item = value;
            Node* x = left;
            for (int i = 0; i < position - 1; i++) {
                x = x->next;
            }
            newNode->next = x->next;
            newNode->prevece = x;
            if (x->next != NULL) {
                x->next->prevece = newNode;
            }
            x->next = newNode;
            length++;
        }
    }

    void removeLeft() {
        if (length == 0) {
            cout << "The List Is Empty" << endl;
            return;
        }
        Node* current = left;
        left = left->next;
        if (left != NULL) {
            left->prevece = nullptr;
        } else {
            right = NULL;
        }
        delete current;
        length--;
    }

    void removeRight() {
        if (length == 0) {
            cout << "The List Is Empty" << endl;
            return;
        }
        Node* current = right;
        right = right->prevece;
        if (right != NULL) {
            right->next = NULL;
        } else {
            left = NULL;
        }
        delete current;
        length--;
    }

    void removeAtPosition(int position) {
        if (position <= 0) {
            removeLeft();
        } else if (position >= length - 1) {
            removeRight();
        } else {
            Node* x = left;
            for (int i = 0; i < position; i++) {
                x = x->next;
            }
            x->prevece->next = x->next;
            if (x->next != NULL) {
                x->next->prevece = x->prevece;
            }
            delete x;
            length--;
        }
    }

    void sort() {
        if (length <= 1) return;
        for (Node* i = left; i != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->item.getTitle() > j->item.getTitle()) {
                    swap(i->item, j->item);
                }
            }
        }
    }
    void searchBook(string key, string value) {
        Node* current = left;
        bool found = false;
        while (current != NULL) {
            if ((key == "title" && current->item.getTitle() == value) ||
                (key == "author" && current->item.getAuthor() == value) ||
                (key == "genre" && current->item.getGenre() == value) ||
                (key == "ISBN" && to_string(current->item.getISBN()) == value)) {
                current->item.print();
                found = true;
                cout << "---------------" << endl;
            }
            current = current->next;
        }
        if (!found) {
            cout << "No Books Found With " << key << " = " << value << endl;
        }
    }
    void borrowBook(int ISBN) {
    Node* current = left;
    bool found = false;

    while (current != NULL) {
        if (current->item.getISBN() == ISBN) {
            found = true;
            if (current->item.getAvailability() == true) {
                current->item.setAvailability(false);
                cout << "You have successfully borrowed the book: " << ISBN << endl;
            } else {
                cout << "Sorry, this book is already borrowed." << endl;
            }
            break;
        }
        current = current->next;
    }

    if (!found)
        cout << "Book not found in the library.\n";
}

    int totalBooks()  {
        return length;
    }

    int availableBooks()  {
        int count = 0;
        Node* current = left;
        while (current != NULL) {
            if (current->item.getAvailability()) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    int borrowedBooks()  {
        return totalBooks() - availableBooks();
    }

    void showStatistics() {
        int total = length;
        int available = availableBooks();
        int borrowed = borrowedBooks();
        cout << "Total Books: " << total << endl;
        cout << "Available Books: " << available << endl;
        cout << "Borrowed Books: " << borrowed << endl;
    }

    Iterator iteratorBegin() {
        return Iterator(left);
    }

    Iterator iteratorEnd() {
        return Iterator(right);
    }

    void print()  {
        Node* current = left;
        while (current != NULL) {
            current->item.print();
            current = current->next;
        }
    }


};


#endif // DOUBLELINKEDLIST_H
