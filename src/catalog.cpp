#include "catalog.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <unistd.h>

    Catalog::Catalog() {
        std::ifstream fin("books/catalog.txt");
        std::string str;
        std::stringstream ss;
        Trio aux;
        int pos, size;

        if(!fin) { // check if the file exists
            fprintf(stderr, "\n\n\nError: 'books/catalog.txt' is missing, the program stopped!\n");
            exit(1);
        }

        fin >> this->numOfBooks; // first line contains the number of books

        std::getline(fin, str); // I don't need the buffer

        while(std::getline(fin, str)) { // "id howMany bookName" is on each line

            size = str.length() - 1;
            for(pos = 0; pos < size; pos++) // removing consecutive spaces
                if(str[pos] == ' ' && str[pos + 1] == ' ') str.erase(pos--, 1);

            while(str[0] == ' ' && str.size()) str.erase(0, 1); // removing the spaces from the start

            if(str[str.size() - 1] == ' ') str.erase(str.size() - 1, 1); // and from the end

            ss << str; // "%d %d string" - on each line
            ss >> aux.id >> aux.count;

            pos = str.find_first_of(" "); // I am making the string to containg only the book's name
            str = str.substr(pos + 1);

            pos = str.find_first_of(" ");
            aux.name = str.substr(pos + 1);

            this->data.push_back(aux); // saving the data
            this->mapData[aux.name] = aux.id;

            ss.str("");
        }

        fin.close();
    }

    int Catalog::searchBook(std::string name) {
        if(this->mapData.count(name)) return mapData[name];
        return -1;
    }

    void Catalog::updateCatalog() {
        std::ofstream fout("books/catalog.txt");
        if(!fout) { // check if the file exists
            fprintf(stderr, "\n\n\nError: 'books/catalog.txt' is missing, the program stopped!\n");
            exit(1);
        }

        /*
            Catalog.txt format:
            | x | -> number of books (-1 < x < 1000)
            | 1 y name1 |-> y is the number of books (-1 < y < 1000) and name1 is the name of the book1
            | 2 z name2 |-> z is the number of books (-1 < z < 1000) and name2 is the name of the book2
            | ......... |
            | x t namex |-> same as before
        */

        fout << std::setw(MAX_DIGITS) << this->numOfBooks << "\n";
        for(auto book : this->data)
            fout << std::setw(MAX_DIGITS) << book.id << " "
                 << std::setw(MAX_DIGITS) << book.count
                 << " " + book.name + "\n";

        fout.close(); // I totally forgot about this...
        fout.open("books/prices.txt");
        if(!fout) {
            fprintf(stderr, "\n\n\nError: 'books/prices.txt' is missing, the program stopped!\n");
            exit(1);
        }

        /*
            Prices.txt format:
            | id price |
        */

        for(auto book : this->prices)
            fout << std::setw(MAX_DIGITS) << book.first << " " << book.second << "\n";

        fout.close();
    }

    void Catalog::showCatalog() {
        for(auto book : this->data)
            std::cout << std::setw(MAX_DIGITS) << book.id << " "
                      << std::setw(MAX_DIGITS) << book.count
                      << " " + book.name + "\n";
    }

    void Catalog::addBook(Book book) {
        if(this->searchBook(book.getName()) != -1) { // the book already exists
            std::cout << "The book already exists!\n";
            return;
        }

        Trio aux;
        aux.count = book.getCount();
        aux.id = book.getId();
        aux.name = book.getName();

        this->data.push_back(aux);
        this->mapData[aux.name] = aux.id;

        std::ofstream fout("books/prices.txt", std::ios::app); // appending the file

        if(!fout) {
            fprintf(stderr, "'books/prices.txt' is missing! The program is not going further!\n");
            return;
        }

        fout.close();

        double newPrice = 0; // at first it may be free, idk lol
        char buffer[1000];
        bool isOk = false;
        std::string str;

        while(!isOk) {

            std::cout << "Choose the price the book will have: ";

            fgets(buffer, 1000, stdin); // user input without new line character
            buffer[strlen(buffer) - 1] = '\0';

            str = buffer;

            try { // trying to convert the string to double
                newPrice = std::stod(str);
                isOk = true;
            } catch (...) { // the user is somehow unable to write a number down wtf
                fprintf(stderr, "The price is not valid! Please try again with a number only!\n");
              }
        }

        ++this->numOfBooks;
        this->prices[book.getId()] = newPrice;    // | id price | - format in price.txt
        this->mapData[book.getName()] = book.getId();
        this->updateCatalog();              // saves the new book and updates the catalog
    }

    void Catalog::removeBook(Book book) {
        if(!prices.count(book.getId())) {
            fprintf(stderr, "Book doesn't exist!\n");
            return;
        }

        prices.erase(book.getId());

        std::list<Trio>::iterator aBook = this->data.begin(); // the only way I know how to erase with an iterator
        for(; aBook != this->data.end(); aBook++)
            if((*aBook).name == book.getName()) {
                this->data.erase(aBook);
                break;
            }

        --this->numOfBooks;
        this->updateCatalog();
    }

    // TODO: create / remove the book file