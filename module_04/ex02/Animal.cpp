/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:22:58 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:22:59 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Random") {
    std::cout << "Animal default constructor called: " << getType() <<std::endl;
}

Animal::Animal(const Animal& other): type(other.getType()) {
    std::cout << "Animal copy constructor called: " << getType() << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called: " << getType() << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignement operator called: " << getType() << std::endl;
    if (this != &other)
        type = other.getType();
    return *this;
}

const std::string& Animal::getType() const {
    return type;
}

void   Animal::setType(const std::string& type) {
    this->type = type;
}
