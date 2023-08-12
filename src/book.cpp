#include "book.h"
#include <fstream>

    Book::Book(int year, int count, std::string name, std::string author, std::string description) {
        this->year = year;
        this->count = count;
        this->name = name;
        this->author = author;
        this->description = description;
    }

    Book::Book(int year, int count, std::string name, std::string author) {
        this->year = year;
        this->count = count;
        this->name = name;
        this->author = author;
        this->description = "-";
    }

    Book::Book(int year, int count, std::string name) {
        this->year = year;
        this->count = count;
        this->name = name;
        this->author = "-";
        this->description = "-";
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

    void Book::addToCatalog() {
        std::ofstream fout("books/catalog.txt");
        if(!fout) std::cout << "welp\n";
        fout << "Hello World\n";
        fout.close();
    }

    Book::~Book() {
        static int destroyCounter = 0;
        if(!destroyCounter++) std::cout << "The book \"" << this->name << "\" was destroyed by the admin.\n<Lucky8boy>: f\n";
        else std::cout << "The book \"" << this->name << "\" was destroyed by the admin.\n<Lucky8boy>: f x" << destroyCounter <<'\n';
    }