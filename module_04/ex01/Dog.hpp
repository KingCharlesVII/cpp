/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:24:14 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:24:17 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "Brain.hpp"
#include "Animal.hpp"

class Dog: public Animal {
    public:
        Dog();
        Dog(const Dog& other);
        virtual ~Dog();
        Dog& operator=(const Dog& other);
        virtual void makeSound() const;
        Brain* getBrain() const;
    private:
        Brain *brain;
};
