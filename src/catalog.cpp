#include "catalog.h"
#include <iostream>
#include <fstream>
#include <sstream>

    Catalog::Catalog() {
        std::ifstream fin("books/catalog.txt");
        std::string str;
        std::stringstream ss;
        Trio aux;
        int pos;

        if(!fin) {
            fprintf(stderr, "\n\n\nError: 'books/catalog.txt' is missing, the program stopped!\n");
            exit(1);
        }

        fin >> this->numOfBooks; // first line contains the number of books

        std::getline(fin, str); // I don't need the buffer

        while(std::getline(fin, str)) { // "id howMany bookName" is on each line
            ss << str;
            ss >> aux.id >> aux.count;

            pos = str.find_first_of(" "); // I am making the string to containg only the book's name
            str = str.substr(pos + 1);

            pos = str.find_first_of(" ");
            aux.name = str.substr(pos + 1);

            this->data.push_back(aux);
            ss.str("");
        }

        fin.close();
    }

    void Catalog::showCatalog() {
        for(auto book : this->data)
            std::cout << book.id << " " << book.count << " " + book.name + "\n";
    }