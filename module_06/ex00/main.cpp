#include <iostream>

#include "ScalarConverter.hpp"

int     main() {
    {
        std::cout << "Test 0:" << std::endl;
        ScalarConverter::convert("42");
        std::cout << std::endl;
        ScalarConverter::convert("42.0f");
        std::cout << std::endl;
        ScalarConverter::convert("42.0");
        std::cout << std::endl;
        ScalarConverter::convert("*");
        std::cout << std::endl;
    }
    {
        std::cout << "Test 1:" << std::endl;
        ScalarConverter::convert("nan");
        std::cout << std::endl;
        ScalarConverter::convert("nanf");
        std::cout << std::endl;
        ScalarConverter::convert("+inf");
        std::cout << std::endl;
        ScalarConverter::convert("-inf");
        std::cout << std::endl;
        ScalarConverter::convert("+inff");
        std::cout << std::endl;
        ScalarConverter::convert("-inff");
        std::cout << std::endl;
    }
    {
        std::cout << "Test 2:" << std::endl;
        ScalarConverter::convert("-42");
        std::cout << std::endl;
        ScalarConverter::convert("-42.0f");
        std::cout << std::endl;
        ScalarConverter::convert("-42.0");
        std::cout << std::endl;
    }
    {
        std::cout << "Test 3:" << std::endl;
        ScalarConverter::convert("-+42");
        std::cout << std::endl;
        ScalarConverter::convert("4-2.0f");
        std::cout << std::endl;
        ScalarConverter::convert("42.0abcdef");
        std::cout << std::endl;
        ScalarConverter::convert("42-");
        std::cout << std::endl;
        ScalarConverter::convert("f42.0f");
        std::cout << std::endl;
        ScalarConverter::convert("42.f");
        std::cout << std::endl;
        ScalarConverter::convert("42.");
        std::cout << std::endl;
        ScalarConverter::convert(".42");
        std::cout << std::endl;
        ScalarConverter::convert("4.2.1");
        std::cout << std::endl;
    }
    {
        std::cout << "Test 4:" << std::endl;
        ScalarConverter::convert("a");
        std::cout << std::endl;
        ScalarConverter::convert("13");
        std::cout << std::endl;
        ScalarConverter::convert("-");
        std::cout << std::endl;
        ScalarConverter::convert(" ");
        std::cout << std::endl;
        ScalarConverter::convert("zz");
        std::cout << std::endl;
        ScalarConverter::convert("b");
        std::cout << std::endl;
        ScalarConverter::convert("&");
        std::cout << std::endl;
        ScalarConverter::convert("128");
        std::cout << std::endl;
    }
    {
        std::cout << "Test 4:" << std::endl;
        ScalarConverter::convert("2147483647");
        std::cout << std::endl;
        ScalarConverter::convert("2147483648");
        std::cout << std::endl;
    }
    {
        std::cout << "Test 5:" << std::endl;
        ScalarConverter::convert("   2147483647");
        std::cout << std::endl;
        ScalarConverter::convert("2147483648   ");
        std::cout << std::endl;
    }
}