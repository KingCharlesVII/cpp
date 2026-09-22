#pragma once

#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class Span {
    public:
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);
        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
        template<typename Iterator>
        void    addNumber(Iterator begin, Iterator end);
    private:
        Span();
        std::vector<int> numbers;
        unsigned int size;
};

#include "Span.hpp"