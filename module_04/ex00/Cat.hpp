/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:23:45 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:23:46 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "Animal.hpp"

class Cat: public Animal {
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        virtual ~Cat();
        virtual void makeSound() const;
};
