#ifndef BOOK_H
#define BOOK_H

    #include <iostream>

    class Book {
        private:
            int year = 1970, count = 1, id = 0;
            std::string name = "Book Class", author = "Lucky8boy", description = "Some cool description!";

        public:
            Book(int count, std::string name);                                                        // (maybe someone will need it)
            Book(int id, int count, std::string name);                                                // I use this for the catalog
            Book(int year, int count, std::string name, std::string author);                          // (maybe someone will need it)
            Book(int year, int count, std::string name, std::string author, std::string description); // I use this for the menu

            void displayBook();             // show all informations about a book
            void addToCatalog();            // add a book file              (maybe someone will need it)

            void setId(int id);             // sets an id for a book
            void setCount(int count);       // sets the number of copies    (maybe someone will need it)
            void setName(std::string name); // sets the name of the book    (maybe someone will need it)

            int getId();                    // gets id
            int getCount();                 // gets count
            std::string getName();          // gets name

            void createFile();              // creates a .txt file for the book
            void destroyFile();             // destroys a .txt file of a book

            // ~Book();                     // this is just an easter egg, still very funny for me lol
    };

#endif