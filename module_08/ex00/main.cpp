#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <vector>

#include "easyfind.hpp"

#define Size(array) (sizeof(array) / sizeof(array[0]))
#define ListBegin(array) (array)
#define ListEnd(array) (ListBegin(array) + Size(array))

int main() {
    {
        int array[] = {
            0,
            1,
            2,
            3,
            4,
            5
        };
        try {
            std::vector<int> vect(ListBegin(array), ListEnd(array));
            std::vector<int>::iterator it(easyfind(vect, 6));
        } catch(const std::exception& e) {
            std::cout << "1) " << e.what() << std::endl;
        }
        }
            {
            int array[] = {
                0,
                1,
                2,
                3,
                4,
                5
            };
            try {
                const std::vector<int> vect(ListBegin(array), ListEnd(array));
                std::vector<int>::const_iterator it(easyfind(vect, 6));
            } catch(const std::exception& e) {
                std::cout << "2) " <<  e.what() << std::endl;
            }
        }
        {
            int array[] = {
                0,
                1,
                2,
                3,
                4,
                5
            };
            try {
                const std::vector<int> vect(ListBegin(array), ListEnd(array));
                std::vector<int>::const_iterator it(easyfind(vect, 5));
                std::cout << "3) " << "Value found is at index: " << *it << std::endl;
            } catch(const std::exception& e) {
                std::cout << "3) " <<  e.what() << std::endl;
            }
        }
        
}