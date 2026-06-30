#include "Array.hpp"

template<typename T>
Array<T>::Array(): data(NULL), _size(0) {
    std::cout << "Default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n): data(new T[n]), _size(n)  {
    std::cout << "Overloaded constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array<T>& other): data(new T[other.size()]), _size(other.size()) {
    std::cout << "Copy consructor called" << std::endl;
    for (unsigned int index(0); index < size(); index++) {
        data[index] = other.data[index];
    }
}

template<typename T>
Array<T>::~Array() {
    std::cout << "Destructor called" << std::endl;
    delete[] data;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] data;
        _size = other.size();
        data = new T[size()];
            for (unsigned int index(0); index < size(); index++) {
        data[index] = other.data[index];
        }
    }
    return (*this);
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= size())
        throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= size())
        throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}
