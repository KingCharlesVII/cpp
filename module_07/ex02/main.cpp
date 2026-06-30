#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

#include "Array.hpp"

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

#define Size(array) (sizeof(array) / sizeof(array[0]))

int main( void ) {
    {
        try {
            Array<std::string> array(3);
            array[0] = std::string("Hello");
            array[1] = std::string("world");
            array[2] = std::string("!");

            Array<std::string> array_deep_copy(array);
            for (std::string::size_type index(0); index < array_deep_copy.size(); index++) {
                std::cout << std::string(array_deep_copy[index]) << " ";
            }
            std::cout << std::endl;
        } catch(const std::bad_alloc& e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            Array<std::string> array(2);
            array[3] = 2;
        } catch (const std::out_of_range& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}