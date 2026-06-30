#include "Array.hpp"

Array::Array(): data(NULL), size(0) {
    std::cout << "Default constructor called" << std::endl;
}

Array::Array(unsigned int n): data(new[n]), _size(n)  {
    std::cout << "Overloaded constructor called" << std::endl;
    if (size() > 1 && data == NULL)
        throw std::bad_alloc("Memory allocation failed");
}

Array::Array(const Array& other): data(new[other.size]), _size(other.size()) {
    std::cout << "Copy consructor called" << std::endl;
    if (size() > 1 && data == NULL)
        throw std::bad_alloc("Memory allocation failed");
    data = *other.data;
}

Array::~Array() {
    std::cout << "Destructor called" << std::endl;
    delete[] data;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete data;
        data = new[other.size()];
        data = *other.data;
    }
    return (*this);
}

const T& Array::operator[](unsigned int index) const {
    if (index > size() || data == NULL)
        throw std::exception();
    return data[index];
}

unsigned int size() const {
    return _size;
}
