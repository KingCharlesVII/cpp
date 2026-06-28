#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>
#include <typeinfo>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static const int MY_RAND_MAX(3);

Base *generate(void) {
    int randomGeneration(std::rand() % MY_RAND_MAX);
    switch(randomGeneration) {
        case 0:
            return (new A());
        case 1:
            return (new B());
        default:
            return NULL;
    }
    return NULL;
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "Type of the object pointed to by p: A" << std::endl;
        return;
    }
    if (dynamic_cast<B *>(p)) {
        std::cout << "Type of the object pointed to by p: B" << std::endl;
        return;
    }
    if (dynamic_cast<C *>(p)) {
        std::cout << "Type of the object pointed to by p: C" << std::endl;
        return;
    }
    std::cout << "Type not known" << std::endl;
   
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::bad_cast& e) {
        (void)e;
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::bad_cast& e) {
        (void)e;
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::bad_cast& e) {
        (void)e;
    }
    std::cout << "Type not known" << std::endl;
}

void    initRandom() {
    std::srand(std::time(NULL));
}

void  generateInstances() {
    for(std::size_t index(0); index < 5; index++) {
        try {
            Base *mock(generate());
            identify(mock);
            identify(*mock);
            delete mock;
        } catch(const std::bad_alloc& e) {
            std::cout << "Memory: " << e.what() << std::endl;
            return;
        }
    }
}

int main() {
    initRandom();
    generateInstances();
}