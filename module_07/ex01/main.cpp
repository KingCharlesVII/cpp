#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

#include "iter.hpp"

void    print(const std::string& str) {
    std::cout << str << " ";
}

void    printint(int& value) {
    std::cout << value << " ";
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
        std::cout << std::endl;
    }
    {
        int numbers[] = {
            1, 
            2,
            3,
            4,
            5
        };
        ::iter(numbers, Size(numbers), increment);
        ::iter(numbers, Size(numbers), printint);
    }
}