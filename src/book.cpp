#include "book.h"

    Book::Book(int year, int count, std::string name, std::string author, std::string description) {
        this->year = year;
        this->count = count;
        this->name = name;
        this->author = author;
        this->description = description;
    }

    void Book::displayBook() {
        std::cout << "========================================================\n"
                  << "Year: " << year <<".\n"
                  << "The bookstore has " << count << " copies of this book.\n"
                  << "Book name: " << name << ".\n"
                  << "Author: " << author << ".\n"
                  << "Description: " << description << ".\n"
                  << "========================================================\n";
    }