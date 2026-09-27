#include <stack>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cctype>

#include "Calculator.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    Calculator calculator;
    Result result(calculator.calculate(argv[1]));
    if (result.error_message.empty() == false) {
        std::cerr << result.error_message << std::endl;
        return 2;
    }
    std::cout << result.value << std::endl;
    return 0;
}