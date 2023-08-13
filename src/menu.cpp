    #include "menu.h"

    // checks if a string begins either with 1, 2, 3, 4 or 5.
    bool isValid(std::string str) {
        std::regex patttern("^[12345]");
        return std::regex_search(str, patttern);
    }

    // it makes the program to sleep for a number of seconds
    void delaySeconds(int seconds) {
        unsigned int timeToGet = time(0) + seconds;
        while(time(0) < timeToGet);   //waiting for the seconds to pass
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