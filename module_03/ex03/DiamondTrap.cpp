/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:59:43 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 11:59:45 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"),ScavTrap(), FragTrap(), name("default")  {
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(30);
    std::cout << "DiamondTrap " << getName() << ": call the default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name) {
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(30);
    std::cout << "DiamondTrap " << getName() << ": call the overloaded constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.getName()) {
    std::cout << "DiamondTrap " << getName() << ": call the copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ScavTrap::operator=(other);
        setName(other.getName());
    }
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << getName() << ": destroy." << std::endl;
}

const std::string& DiamondTrap::getName() const {
    return name;
}

void    DiamondTrap::setName(const std::string& name) {
    this->name = name;
}

void    DiamondTrap::attack(const std::string& target) {
   ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void) {
    std::cout << "I' m " << getName() << std::endl;
    std::cout << "My other name " << ClapTrap::getName() << std::endl;
}
