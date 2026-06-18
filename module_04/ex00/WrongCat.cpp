/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:24:52 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:24:53 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
    std::cout << "WrongCat: " << getType() << ": default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
    std::cout << "WrongCat: " << getType() << ": copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat: " << getType() << ": destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat: " << getType() << ": assignement operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void    WrongCat::makeSound() const {
    std::cout << "WronCat : " << getType() << ": Wrong Meow" << std::endl;
}
