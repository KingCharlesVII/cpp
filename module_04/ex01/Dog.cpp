/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:24:04 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:24:08 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(), brain(new Brain()) {
    std::cout << "Dog: " << getType()  << ": default constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other), brain(new Brain(*other.getBrain())) {
    std::cout << "Dog: " << getType() << ": copy constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog: " << getType() << ": destructor called" << std::endl;
    delete brain;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog: " << getType() << ": assignement operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.getBrain();
    }
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Dog :" << getType() << ": does Woof" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}