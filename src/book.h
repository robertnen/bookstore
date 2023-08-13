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

            void displayBook();
            void addToCatalog();
            void setId(int id);

            // ~Book();
    };

#endif