#pragma once

#include <stack>
#include <string>
#include <cstdlib>
#include <stdexcept>

struct Result {
    int value;
    std::string error_message;
    static Result make_error(const std::string& error_message) {
        Result result;

        result.error_message = error_message;
        return result;
    }
};

class Calculator {
    public:
        Calculator();
        Calculator(const Calculator& other);
        Calculator& operator=(const Calculator& other);
        ~Calculator();
        int evaluate(const char symbol, const int a, const int b) const;
        Result calculate(const std::string& input);
    private:
        bool isoperator(const char symbol) const;
    private:
        std::stack<int> content;
};