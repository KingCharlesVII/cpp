/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:23:20 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:23:21 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal(), brain(new Brain()) {
    std::cout << "Cat: " << getType() << ": default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& other): Animal(other), brain(new Brain(*other.getBrain())) {
    std::cout << "Cat: " << getType() << ": copy constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat: " << getType() << ": destructor called" << std::endl;
    delete brain;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat: " << getType() << ": assignement operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.getBrain();
    }
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Cat: " << getType() << ": does Meow" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}
