#pragma once

#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        ~MutantStack();
        MutantStack& operator=(const MutantStack& other);
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator citerator;
        iterator begin();
        iterator end();
        citerator begin() const;
        citerator end() const;
};

template <typename T>
MutantStack<T>::~MutantStack() {

}

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other): std::stack<T>(other) {

}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
    if (this != &other) 
        std::stack<T>::operator=(other);
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::citerator MutantStack<T>::begin() const {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::citerator MutantStack<T>::end() const {
    return this->c.end();
}