/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:24:25 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:24:27 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called: " << getType() << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.getType()) {
    std::cout << "WrongAnimal copy constructor called: " << getType() << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called: " << getType() << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignement operator called: " << getType() << std::endl;
    if (this != &other)
        type = other.getType();
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal random sound: wrong sound" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return type;
}

void   WrongAnimal::setType(const std::string& type) {
    this->type = type;
}
