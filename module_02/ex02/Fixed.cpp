/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:11:23 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/10 08:11:25 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float toConvert) {
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(toConvert * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    fixedPointValue = fixed.fixedPointValue;
}

Fixed::Fixed(const int toConvert) {
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = toConvert << fractionalBits;
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

float   Fixed::toFloat(void) const {
    return ((float)fixedPointValue / (1 << fractionalBits));
}

int Fixed::toInt(void) const {
    return (fixedPointValue >> fractionalBits);
}

bool    Fixed::operator>(const Fixed& fixed) const {
    return (fixedPointValue > fixed.fixedPointValue);
}

bool    Fixed::operator<(const Fixed& fixed) const {
    return (fixedPointValue < fixed.fixedPointValue);
}

bool    Fixed::operator>=(const Fixed& fixed) const {
    return (fixedPointValue >= fixed.fixedPointValue);
}

bool    Fixed::operator<=(const Fixed& fixed) const {
    return (fixedPointValue <= fixed.fixedPointValue);
}

bool    Fixed::operator==(const Fixed& fixed) const {
    return (fixedPointValue == fixed.fixedPointValue);
}

bool    Fixed::operator!=(const Fixed& fixed) const {
    return (fixedPointValue != fixed.fixedPointValue);
}

Fixed Fixed::operator+(const Fixed& fixed) const {
    return Fixed(fixedPointValue + fixed.fixedPointValue);
}

Fixed Fixed::operator-(const Fixed& fixed) const {
    return Fixed(fixedPointValue - fixed.fixedPointValue);
}

Fixed Fixed::operator*(const Fixed& fixed) const {
    long temp_fixed = (long)fixedPointValue * fixed.fixedPointValue;
    return Fixed((int)(temp_fixed >> fractionalBits));
}

Fixed Fixed::operator/(const Fixed& fixed) const {
    if (fixedPointValue == 0)
        return (Fixed(0));
    long temp_fixed = ((long)fixedPointValue << fractionalBits);
    return Fixed((int)(temp_fixed / fixed.fixedPointValue));
}

Fixed& Fixed::operator++(void) {
    fixedPointValue += (1 << fractionalBits);
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed result(*this);
    fixedPointValue += (1 << fractionalBits);
    return (result);
}

Fixed& Fixed::operator--(void) {
    fixedPointValue -= (1 << fractionalBits);
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed result(*this);
    fixedPointValue -= (1 << fractionalBits);
    return (result);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a: b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b ? a: b);
}


Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a: b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b ? a: b);
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return (os);
}
