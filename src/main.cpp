#include "menu.h"
#include "book.h"
#include "catalog.h"

int main() {

    Menu menu;

    menu.welcome();
    while(menu.getChoice() != 5) {
        menu.getOptions();

        switch(menu.getChoice()) {
            case 1:
                menu.addBookOption();
                break;
            case 2:
                menu.removeBookOption();
                break;
            case 3:
                menu.searchBookOption();
                break;
            case 4:
                menu.buyBookOption();
                break;
            case 5:
                std::cout << "Thanks for looking in our bookstore! Have a nice day!\n";
                break;
            case -1:
                break; // do nothing
            default:
                std::cout << "Something bad happen. Please send an issue about it!\n";
                break;
        }
    }

    return 0;
}