/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:24:32 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:24:33 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        ~WrongAnimal();
        WrongAnimal& operator=(const WrongAnimal& other);
        void makeSound() const;
        const std::string& getType() const;
    protected:
        std::string type;
};
