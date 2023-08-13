#include "catalog.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

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
    }

    void Catalog::showCatalog() {
        for(auto book : this->data)
            std::cout << std::setw(MAX_DIGITS) << book.id << " "
                      << std::setw(MAX_DIGITS) << book.count
                      << " " + book.name + "\n";
    }

    void Catalog::addBook(Book book) {
        if(this->searchBook(book.getName()) != -1)
    }