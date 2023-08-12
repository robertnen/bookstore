#ifndef BOOK_H
#define BOOK_H

    #include <iostream>

    class Book {
        private:
            int year, count;
            std::string name, author, description;
        public:
            Book(int year, int count, std::string name, std::string author, std::string description);
            void displayBook();
    };

#endif