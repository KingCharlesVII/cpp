#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "Copy constructor called" << std::endl;
    (void)other;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "Assignement operator called" << std::endl;
    (void)other;
    return *this;
}

bool    isDisplayable(unsigned char c) {
    return std::isprint(c);
}

bool    isMathSymbol(const std::string& representation) {
    return (representation == "-inff" || representation == "+inff" || representation == "nanf" || representation == "-inf" || representation == "+inf" || representation == "nan");
}

bool    isSign(char c) {
    return (c == '+' || c == '-');
}

bool    isPunct(char c) {
    return (c == '.');
}

bool    isFloatSymbol(char c) {
    return (c == 'f');
}

bool    isNumberSymbol(char c) {
    return (std::isdigit(c) || isSign(c) || isPunct(c) || isFloatSymbol(c));
}

bool    checkSymbols(const std::string& representation) {
    std::size_t sign(0);
    std::size_t dot(0);
    std::size_t floatSign(0);
    for (std::string::size_type index(0); index < representation.size(); index++) {
        if (!isNumberSymbol(representation[index]))
            return false;
        if (isPunct(representation[index]))
            dot++;
        if (isFloatSymbol(representation[index]))
            floatSign++;
        if (isSign(representation[index]))
            sign++;
    }
    return (sign < 2 && dot < 2 && floatSign < 2);
}

bool    checkSymbolPosition(const std::string& representation) {
    std::size_t plus(0);
    std::size_t less(0);
    std::size_t dot(0);
    std::size_t floatSign(0);

    plus = representation.find("+");
    if (plus != std::string::npos && plus != 0)
        return false;
    less = representation.find("-");
    if (less != std::string::npos && less != 0)
        return false;
    dot = representation.find(".");
    if (dot != std::string::npos && (dot == 0 || (dot == representation.size() - 1) || !isdigit(representation[dot + 1])))
        return false;
    floatSign = representation.find("f");
    if (floatSign != std::string::npos && (floatSign != (representation.size() - 1)))
        return false;
    return true;
}

bool    checkNumber(const std::string& representation) {
    if(representation.empty())
        return false;
    if (representation.size() == 1)
        return true;
    if (isMathSymbol(representation))
        return true;
    if (isSign(representation[0])) {
        if (!std::isdigit(representation[1]))
            return false;
    }
    else if (!std::isdigit(representation[0]))
        return false;
    if (!checkSymbols(representation))
        return false;
    if (!checkSymbolPosition(representation))
        return false;
    return true;
}

void    printImpossible() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void    printMathSymbol(const std::string& representation) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << ((representation.find("f", 4) == std::string:: npos) ? (representation + "f") : representation) << std::endl;
    std::cout << "double: " << ((representation.find("f", 4) == std::string:: npos) ?  representation : representation.substr(0, representation.size())) << std::endl;
}

void    printChar(char c, bool outOfRange = false) {
    if (outOfRange) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (!isDisplayable(c)) {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: \'" << c << "\'" << std::endl;
}

void    printInt(int number, bool outOfRange = false) {
    if (outOfRange) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << number << std::endl;
}

void    printFloat(float number, bool outOfRange = false) {
    if (outOfRange) {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    std::cout << "float: " << std::setprecision(1) << std::fixed << number << "f" << std::endl;
}

void    printDouble(double number) {
    std::cout << "double: " << std::setprecision(1) << std::fixed << number << std::endl;
}

void ScalarConverter::convert(const std::string& representation) {
    if (!checkNumber(representation)) {
        printImpossible();
        return;
    }
    if (isMathSymbol(representation)) {
        printMathSymbol(representation);
        return;
    }
    double value(std::strtod(representation.c_str(), NULL));
    bool intOverFlow(value > INT_MAX || value < INT_MIN);
    bool charOverFlow(value > CHAR_MAX || value < CHAR_MIN);
    bool floatOverFlow(value > FLT_MAX || value < -FLT_MAX);
    if ((isdigit(representation[0]) == false) && representation.size() == 1) {
        printChar(static_cast<unsigned char>(representation[0]));
        printInt(static_cast<int>(representation[0]));
        printFloat(static_cast<float>(representation[0]));
        printDouble(static_cast<double>(representation[0]));
        return;
    }
    {
        if (charOverFlow)
            printChar(static_cast<char>(value), true);
        else
            printChar(static_cast<char>(value));
        if (intOverFlow)
            printInt(static_cast<int>(value), true);
        else
            printInt(static_cast<int>(value));
        if (floatOverFlow)
            printFloat(static_cast<float>(value), true);
        else
            printFloat(static_cast<float>(value));
        printDouble(value);
    }
}