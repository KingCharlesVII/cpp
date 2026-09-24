#include "Span.hpp"

Span::Span(unsigned int N): size(N) {

}

Span::Span(const Span& other): numbers(other.numbers), size(other.size) {

}

Span::~Span() {
    
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        numbers = other.numbers;
        size= other.size;
    }
    return *this;
}

void   Span::addNumber(int number) {
    if (numbers.size() >= size)
        throw std::runtime_error("Span is full");
    numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());
    int shortest(sorted[1] - sorted[0]);
    for (std::size_t index(1); index < sorted.size(); index++) {
        int span(sorted[index] - sorted[index - 1]);
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::vector<int>::const_iterator min = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator max = std::max_element(numbers.begin(), numbers.end());
    return (*max - *min);
}