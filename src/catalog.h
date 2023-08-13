#ifndef CATALOG_H
#define CATALOG_H

    #include <iostream>
    #include <list>

    typedef struct Trio {
        int id, count;
        std::string name;
    } Trio;

    class Catalog {
        private:
            std::list<Trio> data;
            int numOfBooks;
        public:
            Catalog();
            int searchBook();
            void updateCatalog();
            void showCatalog();
    };

#endif