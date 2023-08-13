#ifndef BOOK_H
#define BOOK_H

    #include <iostream>

    class Book {
        private:
            int year = 1970, count = 1, id = 0;
            std::string name = "Lorem ipsum", author = "Lucky8boy", description = "Some cool description!";

        public:
            Book(int year, int count, std::string name, std::string author, std::string description);
            Book(int year, int count, std::string name, std::string author);
            Book(int year, int cuont, std::string name);

            void displayBook();    // show all informations about a book
            void addToCatalog();   // adds a book to the catalog (I saw later that this function is useless for me)
            void setId(int id);    // sets an id for a book

            std::string getName(); // gets name
            int getId();           // gets id
            int getCount();        // gets count

            void createFile();      // creates a .txt file for the book
            void destroyFile();     // destroys a .txt file of a book

            // ~Book();
    };

#endif