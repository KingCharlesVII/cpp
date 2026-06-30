#pragma once

#include <exception>
#include <iostream>

template<typename T>
class Array {
    public:
        Array();
        Array(const Array& other);
        Array(unsigned int n);
        ~Array();
        Array& operator=(const Array& other);
        const T& operator[](unsigned int index) const;
        T& operator[](unsigned int index);
        unsigned int size() const;
    private:
        T* data;
        unsigned int _size;
};

#include "Array.tpp"