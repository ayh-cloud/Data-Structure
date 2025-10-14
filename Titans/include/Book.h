#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int ISBN;
    string genre;
    bool availability;

public:

    Book() {}


    Book(string title, string author, int ISBN, string genre, bool availability)
    {
        this->title=title;
        this->author=author;
        this->ISBN=ISBN;
        this->genre=genre;
        this->availability=availability;

    }



    string getTitle()
     {
          return title;
     }
    string getAuthor()
     {
         return author;
          }
    int getISBN()
     {
         return ISBN;
          }
    string getGenre()
     {
          return genre;
           }
    bool getAvailability()
    {
        return availability;
        }


    void setTitle(string title)
     {
         this->title = title;
         }
    void setAuthor(string author)
    {
         this->author = author;
         }
    void setISBN(int ISBN)
     {
         this->ISBN = ISBN;
         }
    void setGenre(string genre)
     {
         this->genre = genre;
          }
    void setAvailability(bool availability)
     {
          this->availability = availability;
          }


    void print()  {
        cout << "The Title Is: " << title << endl
             << "The Author Is: " << author << endl
             << "The ISBN Is: " << ISBN << endl
             << "The Genre Is: " << genre << endl
             << "The Availability Is: " << (availability ? "Available" : "Not Available") << endl;
    }

    virtual ~Book() {}
};

#endif // BOOK_H
