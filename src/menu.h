#ifndef MENU_H
#define MENU_H

    #include <iostream>
    #include <cstring>
    #include <regex>

    // checks while using regex if a string contains at start 1, 2, 3, 4 or 5
    bool isValid(std::string str);

    // it makes the program to sleep for a number of seconds
    void delaySeconds(int seconds);

    class Menu {
        private:
            const std::string sWelcome = "Welcome to my bookstore!\n";
            const int option = 5;    //add, remove, check, buy, loan
            const std::string sOptions[5] = {"1. Add book\n",
                                             "2. Remove book\n",
                                             "3. Check if book exists\n",
                                             "4. Buy book\n",
                                             "5. Exit\n"};
            short choice;

        public:
            void welcome();         // welcome message
            void getOptions();      // get options menu
    };

#endif