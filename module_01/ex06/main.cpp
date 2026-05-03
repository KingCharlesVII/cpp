#include <iostream>
#include <string>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
    void debugCall(void);
    void infoCall(void);
    void warningCall(void);
    void errorCall(void);
};

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::debugCall(void) {
    debug();
}
void Harl::infoCall(void) {
    info();
}
void Harl::warningCall(void) {
    warning();
}

void Harl::errorCall(void) {
    error();
}

int getLevel(std::string level) {
    std::string levels [4] =  {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    for (size_t index = 0; index < 4; index++) {
        if (levels[index] == level)
            return (index);
    }
    return (-1);
}

int main(int argc, char **argv) {
    Harl harl;

    if (argc != 2) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (0);
    }
    int level = getLevel(argv[1]);

    switch (level) {
        case 0:
            harl.debugCall();
        case 1:
            harl.infoCall();
        case 2:
            harl.warningCall();
        case 3:
            harl.errorCall();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}