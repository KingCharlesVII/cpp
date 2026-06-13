#pragma once

#include <string>
#include <iostream>

class Animal {
    public:
        Animal();
        Animal(const Animal& other);
        virtual ~Animal();
        Animal& operator=(const Animal& other);
        virtual void makeSound() const;
        const std::string& getType() const;
    protected:
        std::string type;
};

Animal::Animal(): type("Random") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignement operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Random sound" << std::endl;
}

const std::string& Animal::getType() const {
    return type;
}

class Cat: public Animal {
    public:
        Cat();
        Cat(const Cat& other);
        virtual ~Cat();
        Cat& operator=(const Cat& other);
        virtual void makeSound() const;
};

Cat::Cat() {
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignement operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

class Dog: public Animal {
    public:
        Dog();
        Dog(const Dog& other);
        virtual ~Dog();
        Dog& operator=(const Dog& other);
        virtual void makeSound() const;
};

Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignement operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

/*------------------------------------------*/

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        ~WrongAnimal();
        WrongAnimal& operator=(const WrongAnimal& other);
        void makeSound() const;
        const std::string& getType() const;
    protected:
        std::string type;
};

WrongAnimal::WrongAnimal(): type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignement operator called" << std::endl;
    type = other.type;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "Wrong animal random sound" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return type;
}

class WrongCat: public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat& other);
        ~WrongCat();
        WrongCat& operator=(const WrongCat& other);
        void makeSound() const;
};

WrongCat::WrongCat() {
    std::cout << "WrongCat default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assignement operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void    WrongCat::makeSound() const {
    std::cout << "Wrong Meow" << std::endl;
}