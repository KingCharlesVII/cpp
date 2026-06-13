/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:24:42 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:24:43 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat& other);
        ~WrongCat();
        WrongCat& operator=(const WrongCat& other);
        void makeSound() const;
};
