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

#include "Brain.hpp"
#include "Animal.hpp"

class Cat: public Animal {
    public:
        Cat();
        Cat(const Cat& other);
        virtual ~Cat();
        Cat& operator=(const Cat& other);
        virtual void makeSound() const;
        Brain* getBrain() const;
    private:
        Brain *brain;
};
