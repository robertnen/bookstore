#ifndef MENU_H
#define MENU_H

    #include <iostream>
    #include <cstring>
    #include <regex>

    bool isValid(std::string str);

    class Menu {
        private:
            const std::string sWelcome = "Welcome to my bookstore!\n";
            const int option = 5; //add, remove, check, buy, loan
            const std::string sOptions[5] = {"1. Add book\n",
                                            "2. Remove book\n",
                                            "3. Check if book exists\n",
                                            "4. Buy book\n",
                                            "5. Loan book\n"};
            short choice;
        public:
            std::string welcome();
            void getOptions();
    };

#endif