/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 07:54:12 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/10 07:54:14 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        ~Fixed();
        Fixed& operator=(const Fixed& fixed);
        int getRawBits(void) const;
        void setRawBits(const int raw);
};
