/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:17:34 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 11:17:38 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << ": call the default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << ": call te overloaded constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
    std::cout << "FragTrap " << getName() << ": call the copy constructor" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << getName() << ": destroy" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return (*this);
}

void    FragTrap::attack(const std::string& target) {
    if (getHitPoint() == 0) {
        std::cout << "FragTrap " << getName() << ": cannot do anything to " << target << " due to a lack of hit pointd" << std::endl;
        return ;
    }
    if (getEnergyPoint() == 0) {
        std::cout << "FragTrap " << getName() << ": cannot do anything to " << target << "due to a lack of energy points" << std::endl;
        return ;
    }
    setEnergyPoint(getEnergyPoint() - 1);
    std::cout << "FragTrap " << getName() << ": attacks " << target << " causing " << getAttackDamage() << " points of damages!" << std::endl;
}

void FragTrap::highFiveGuys(void) {
    if (getHitPoint() == 0) {
           std::cout << "FragTrap " << getName() << ": cannot have five guys for it is already destroyed" << std::endl;
           return ;
    }
    std::cout << "FragTrap " << getName() << ": request a high five" << std::endl;
}
