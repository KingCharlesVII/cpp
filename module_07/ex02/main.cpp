#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

#include "Array.hpp"

int main( void ) {
    try {
    Array<int> empty;

            std::cout << "Empty array size: " << empty.size() << std::endl;

            try {
                empty[0] = 42;
            } catch (const std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }

            Array<int> array(5);

            for (unsigned int index(0); index < array.size(); index++)
                array[index] = index + 1;

            std::cout << "Array size: " << array.size() << std::endl;

            for (unsigned int index(0); index < array.size(); index++)
                std::cout << array[index] << " ";
            std::cout << std::endl;
        } catch(const std::bad_alloc& e) {
            std::cerr << e.what() << std::endl;
    }
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