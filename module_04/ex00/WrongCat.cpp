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
    std::cout << "WrongCat default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
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
