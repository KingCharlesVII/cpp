#include "Calculator.hpp"

Calculator::Calculator() {
}

Calculator::Calculator(const Calculator& other): content(other.content) {
}

Calculator&  Calculator::operator=(const Calculator& other) {
    if (this != &other) {
        this->content = other.content;
    }
    return *this;
}

Calculator::~Calculator() {
}

int Calculator::evaluate(const char symbol, const int a, const int b) const {
            if (symbol == '+')
                return a + b;
            if (symbol == '-')
                return a - b;
            if (symbol == '*')
                return a * b;
            if (symbol == '/') {
                if (b == 0)
                    throw std::runtime_error("Error");
                return a / b;
            }
            return 0;
}

Result Calculator::calculate(const std::string& input) {
           Result result;

            for (std::size_t index(0); index < input.length(); index++) {
                char symbol(input[index]);
                if (std::isspace(symbol))
                    continue;
                if (std::isdigit(symbol))
                    content.push(symbol - '0');
                else if (isoperator(symbol)) {
                    if (content.size() < 2)
                        return Result::make_error("Error");
                    int b(content.top());
                    content.pop();
                    int a(content.top());
                    content.pop();
                    try {
                        int result_value(evaluate(symbol, a, b));
                        content.push(result_value);
                    } catch (const std::exception& e) {
                        return Result::make_error(e.what());
                    }
                }
                else {
                    return Result::make_error("Error");
                }
            }
            if (content.size() != 1)
                return Result::make_error("Error");
            result.value = content.top();
            return result;
}

bool Calculator::isoperator(const char symbol) const {
    return (symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-');
}