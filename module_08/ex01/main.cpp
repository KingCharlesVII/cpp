#include <iostream>
#include <vector>
#include <cstdlib>
#include <exception>

#include "Span.hpp"

int main() {
    {
        try {
            Span span(5);

            span.addNumber(6);
            span.addNumber(3);
            span.addNumber(17);
            span.addNumber(9);
            span.addNumber(11);

            std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
            std::cout << "Longest span: " << span.longestSpan() << std::endl;
        } catch(const std::exception& e) {
            std::cout << "1) " << e.what() << std::endl;
        }
    }

    {
        try {
            Span span(2);

            span.addNumber(10);
            span.addNumber(20);

            std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
            std::cout << "Longest span: " << span.longestSpan() << std::endl;

            span.addNumber(30);
        } catch(const std::exception& e) {
            std::cout << "2) " << e.what() << std::endl;
        }
    }

    {
        try {
            Span span(1);

            span.addNumber(42);

            std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        } catch(const std::exception& e) {
            std::cout << "3) " << e.what() << std::endl;
        }
    }

    {
        try {
            Span span(10);

            std::vector<int> numbers;

            numbers.push_back(1);
            numbers.push_back(100);
            numbers.push_back(50);
            numbers.push_back(25);
            numbers.push_back(75);

            span.addNumber(numbers.begin(), numbers.end());

            std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
            std::cout << "Longest span: " << span.longestSpan() << std::endl;
        } catch(const std::exception& e) {
            std::cout << "4) " << e.what() << std::endl;
        }
    }

    {
        try {
            Span span(3);

            std::vector<int> numbers;

            numbers.push_back(1);
            numbers.push_back(2);
            numbers.push_back(3);
            numbers.push_back(4);

            span.addNumber(numbers.begin(), numbers.end());
        } catch(const std::exception& e) {
            std::cout << "5) " << e.what() << std::endl;
        }
    }
}