/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:03:22 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/10 08:03:24 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int toConvert) {
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = toConvert << fractionalBits;
}

Fixed::Fixed(const float toConvert) {
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(toConvert * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& fixed): fixedPointValue(fixed.fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        fixedPointValue = fixed.fixedPointValue;
    return (*this);
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

void Fixed::setRawBits(const int raw) {
    fixedPointValue = raw;
}

float   Fixed::toFloat(void) const {
    return ((float)fixedPointValue / (1 << fractionalBits));
}

int Fixed::toInt(void) const {
    return (fixedPointValue >> fractionalBits);
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return (os);
}
