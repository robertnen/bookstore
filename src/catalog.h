#ifndef CATALOG_H
#define CATALOG_H

    #include <iostream>
    #include <list>
    #include <unordered_map>

    #define MAX_DIGITS 3 // how many digits an Id can have (in this case -1 < Id < 1000)

    typedef struct Trio {
        int id, count;
        std::string name;
    } Trio;

    /*
        The "catalog" is made of a list and an unordered map. The list is used
        to containg everything, and the map is used to find easier some info.
    */

    class Catalog {
        private:
            std::unordered_map<std::string, int> mapData;
            std::list<Trio> data;
            int numOfBooks;
        public:
            Catalog(); // it gets from the 'books/catalog.txt' all the data the bookstore has
            int searchBook(std::string name); // it returns the id of the search book or -1 if not found
            void updateCatalog(); // it rewrites the catalog (maybe major changes)
            void showCatalog(); // writes all the catalog to the terminal
    };

#endif