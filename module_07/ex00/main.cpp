#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

#include "whatever.hpp"

static std::size_t tests;

void    print_success() {
    std::cout << "Test " << tests << " passed" << std::endl;
    tests++;
}

#define ASSERT_EQ(actual, expected) \
    do { \
        if (actual != expected) {\
            std::cout << "[Error]: " << actual << " is different from " << expected << std::endl; \
            std::exit(1); \
        } \
        print_success(); \
    }   while (0)

#define ASSERT_NE(actual, expected) \
    do { \
        if (actual == expected) {\
            std::cout << "[Error]: " << actual << " is equal to " << expected << std::endl; \
            std::exit(1); \
        } \
        print_success(); \
    }   while (0)

#define ASSERT_TRUE(actual) \
    do { \
        if (actual == false) {\
            std::cout << "[Error]: " << actual << " is false" << std::endl; \
            std::exit(1); \
        } \
        print_success(); \
    }   while (0)

#define ASSERT_FALSE(actual) \
    do { \
        if (actual == true) {\
            std::cout << "[Error]: " << actual << " is true" << std::endl; \
            std::exit(1); \
        } \
        print_success(); \
    }   while (0)

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}