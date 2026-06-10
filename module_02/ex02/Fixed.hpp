/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:11:33 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/10 08:11:36 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();

        Fixed(const int toConvert);
        Fixed(const float toConvert);

        float toFloat(void) const;
        int toInt(void) const;

        bool    operator>(const Fixed& fixed) const;
        bool    operator<(const Fixed& fixed) const;
        bool    operator>=(const Fixed &fixed) const;
        bool    operator<=(const Fixed &fixed) const;
        bool    operator==(const Fixed& fixed) const;
        bool    operator!=(const Fixed& fixed) const;

        Fixed operator+(const Fixed&  fixed) const;
        Fixed operator-(const Fixed&  fixed) const;
        Fixed operator/(const Fixed&  fixed) const;
        Fixed operator*(const Fixed&  fixed) const;

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
      
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);
