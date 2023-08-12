#include "menu.h"
#include "book.h"
#include <iostream>
int main() {

    Menu menu;
    menu.welcome();
    menu.getOptions();

    Book book(2000, 2, "Name", "Author", "Lorem ipsum");
    book.displayBook();

    return 0;
}