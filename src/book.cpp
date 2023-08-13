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
        std::ofstream fout("books/catalog.txt", std::ios::app);
        if(!fout) {
            system("mkdir books; cd books; touch catalog.txt; cd -");
            std::cout << "Added catalog.txt because someone messed up wtf.\n";
        }
        fout << this->id << " " << this->count << " " + this->name + "\n";
        fout.close();
    }

    void Book::setId(int id) {
        this->id = id;
    }

    std::string Book::getName() {
        return this->name;
    }

    int Book::getId() {
        return this->id;
    }

    int Book::getCount() {
        return this->count;
    }

    void Book::createFile() {
        std::string path = "books/" + this->name + ".txt";

        if(this->name == "catalog" || this->name == "prices") {
            std::cout << "Choose a different name for the book!\n";
            return;
        }
    }

    // Book::~Book() {
    //     static int destroyCounter = 0;
    //     if(!destroyCounter++) std::cout << "The book \"" << this->name << "\" was destroyed by the admin.\n<Lucky8boy>: f\n";
    //     else std::cout << "The book \"" << this->name << "\" was destroyed by the admin.\n<Lucky8boy>: f x" << destroyCounter <<'\n';
    // }