#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

#include "iter.hpp"

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

void    print(const std::string& str) {
    std::cout << str << " ";
}

void    increment(int& number) {
    number += 1;
}

#define Size(array) (sizeof(array) / sizeof(array[0]))

int main( void ) {
    {
        const std::string array[] = {
            "hello",
            ",",
            "how",
            "are",
            "you",
            "?"
        };
        ::iter(array, Size(array), print);
    }
    {
        const int numbers[] = {
            1, 
            2,
            3,
            4,
            5
        };
        ::iter(numbers, Size(numbers), increment);
    }
}