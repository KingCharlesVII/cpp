/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:03:34 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/10 08:03:36 by gmurzi           ###   ########.fr       */
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
        Fixed(const int toConvert);
        Fixed(const float toConvert);
        ~Fixed();
        Fixed& operator=(const Fixed& fixed);
        int getRawBits(void) const;
        void setRawBits(const int raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);
