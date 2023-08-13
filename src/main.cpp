#include "menu.h"
#include "book.h"
#include "catalog.h"
#include <iostream>
int main() {

    Menu menu;
    // menu.welcome();
    // menu.getOptions();

    Book book1(2000, 2, "Name", "Author", "Lorem ipsum"), book2(1900, 1, "Name2", "Author2"), book3(1945, 15, "Name3");
    // book1.displayBook();
    book1.createFile();
    book1.destroyFile();
    // book2.displayBook();
    // book3.displayBook();

    // book1.addToCatalog();
    // book1.addToCatalog();
    // book1.addToCatalog();

    Catalog catalog;
    // catalog.showCatalog();
    // catalog.searchBook("Very cool name");
    book1.setId(3);
    book2.setId(2);
    book3.setId(1);
    catalog.addBook(book1);
    catalog.addBook(book2);
    catalog.addBook(book3);
    catalog.removeBook(book2);
    catalog.removeBook(book3);

    return 0;
}