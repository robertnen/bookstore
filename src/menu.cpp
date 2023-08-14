    #include "menu.h"

    bool isValid(std::string str) {
        std::regex patttern("^[12345]");
        return std::regex_search(str, patttern);
    }

    void delaySeconds(int seconds) {
        unsigned int timeToGet = time(0) + seconds;
        while(time(0) < timeToGet);   // waiting for the seconds to pass
    }

    void Menu::welcome() {
        std::cout << this->sWelcome + "\n";
    }

    void Menu::getOptions() {
        int i = 0, timeout = 3;
        char buffer[1000];
        std::cout << "Choose an option from the list:\n";
        for(; i < this->option; i++) std::cout << this->sOptions[i];

        // user input
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        std::string str(buffer);

        while(!isValid(buffer)) {
            std::cout << "Please choose an option between 1 and 5!\n";
            delaySeconds(1);
            for(i = timeout; i > 0; i--) {
                std::cout << "Wait " << i << "s!\r";
                std::cout.flush();
                delaySeconds(1);
            }
            std::cout << "\rTry again: ";
            std::cout.flush();

            timeout += 2;

            // user input
            fgets(buffer, 1000, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }

        this->choice = (short)(buffer[0] - '0');
    }

    int Menu::getChoice() {
        return this->choice;
    }

    void Menu::buyBookOption() {

        system("clear");

        char buffer[1000];
        std::string userInput;

        std::cout << "You want to search the book by the id or by the name?\n 1. Name\n 2. Id\nYour choice: ";
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        userInput = buffer;

        try {
            this->choice = std::stoi(userInput);
        } catch(...) {
            fprintf(stderr, "Error: You have to enter a number between 1 and 2!\n");
            delaySeconds(WAITING_TIME);
            system("clear");
            this->choice = -1;
            return;
        }

        if(this->choice < 1 && this->choice > 2) {
            fprintf(stderr, "Error: You have to enter a number between 1 and 2!\n");
            delaySeconds(WAITING_TIME);
            system("clear");
            this->choice = -1;
            return;
        }

        Catalog catalog;

        if(this->choice == 1) { // by name

            std::cout << "Enter the id of the book: ";
            fgets(buffer, 1000, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            userInput = buffer;

            int id;

            try {
                id = std::stoi(userInput);
            } catch(...) {
                std::cout << "The bookstore doesn't have this book anymore! Sorry!\n";
                delaySeconds(WAITING_TIME);
                system("clear");
                this->choice = -1;
                return;
            }

            if(!catalog.searchBook(id)) {
                std::cout << "The bookstore doesn't have this book anymore! Sorry!\n";
                delaySeconds(WAITING_TIME);
                system("clear");
                this->choice = -1;
                return;
            }

            catalog.buyBook(id);
            delaySeconds(WAITING_TIME);
            system("clear");
            return;
         } else {

            std::cout << "Enter the name of the book: ";
            fgets(buffer, 1000, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            userInput = buffer;

            if(!catalog.searchBook(userInput)) {
                std::cout << "The bookstore doesn't have this book anymore! Sorry!\n";
                delaySeconds(WAITING_TIME);
                system("clear");
                this->choice = -1;
                return;
            }

            catalog.buyBook(userInput);
            delaySeconds(WAITING_TIME);
            system("clear");
            return;
         }
    }

    void Menu::addBookOption() {
        std::string name, author, description;
        int year, count, id;
        char buffer[1000];
        Catalog catalog;

        system("clear");
        std::cout << "The name, number of copies and the year are mandatory (*), if you don't want to write to the others press Enter!\n";

        std::cout << "Write the name* of the book: ";
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        name = buffer;

        if(name.empty()) {
            fprintf(stderr, "Error: The book needs a name!\n");
            delaySeconds(WAITING_TIME);
            system("clear");
            return;
        }

        std::cout << "Write the author of the book: ";
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        author = buffer;

        std::cout << "Write the description of the book: ";
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        description = buffer;

        std::cout << "Write the year of the book: ";
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        try {
            year = std::stoi(buffer);
        } catch(...) {
            std::cout << "Invalid number. The year will be set to -1. Change it in the .txt file!\n";
            year = -1;
        }

        std::cout << "Write the number of copies* of the book: ";
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        try {
            count = std::stoi(buffer);
        } catch(...) {
            std::cout << "Invalid number. The number of copies will be 0. Change it in the .txt file!\n";
            count = -1;
        }

        id = catalog.getNumOfBooks() + 1;

        Book book(year, count, name, author, description);

        system("clear");
        book.displayBook();

        std::cout << "No changes yet to the catalog. Do you want to continue?\n1. Yes\n2. No\nYour choice: ";
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        this->choice = -1;

        while(this->choice == -1) {
            try {
                this->choice = std::stoi(buffer);
            } catch(...) {
                std::cout << "It has to be a number between 1 and 2. Try again!\n";
            }
        }

        if(this->choice == 2) {
            system("clear");
            return;
        }

        catalog.addBook(book);
        std::cout << "The book " + book.getName() + " was added!\n";
        delaySeconds(WAITING_TIME);
        system("clear");
        return;
    }