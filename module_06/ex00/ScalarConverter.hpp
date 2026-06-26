#pragma once

#include <string>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cfloat>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& other);
    public:
        static void convert(const std::string& representation);
};