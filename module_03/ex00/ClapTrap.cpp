/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:28:45 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 10:28:47 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << "ClapTrap " << getName() << ": call the default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): name(name), hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << "Clap trap " << getName() << ": call the overloaded constructor" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << getName() << ": destroy" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): name(other.getName()), hitPoint(other.getHitPoint()), energyPoint(other.getEnergyPoint()), attackDamage(other.getAttackDamage()) {
    std::cout << "ClapTrap " << getName() <<": call the copy constructor" << std::endl;
}

void    ClapTrap::setEnergyPoint(unsigned int energyPoint) {
    this->energyPoint = energyPoint;
}

void    ClapTrap::setAttackDamage(unsigned int attackDamage) {
    this->attackDamage = attackDamage;
}

void    ClapTrap::setHitPoint(unsigned int hitPoint) {
    this->hitPoint = hitPoint;
}

void ClapTrap::setName(const std::string& name) {
    this->name = name;
}

unsigned int ClapTrap::getEnergyPoint() const {
    return energyPoint;
}

unsigned int ClapTrap::getAttackDamage() const {
    return attackDamage;
}

unsigned int ClapTrap::getHitPoint() const {
    return hitPoint;
}

const std::string& ClapTrap::getName() const {
    return name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap " << getName() << ": call assignement operator" << std::endl;
    if (this != &other) {
        setName(other.getName());
        setHitPoint(other.getHitPoint());
        setEnergyPoint(other.getEnergyPoint());
        setAttackDamage(other.getAttackDamage());
    }
    return (*this);
}

void    ClapTrap::attack(const std::string& target) {
    if (getHitPoint() == 0) {
        std::cout << "ClapTrap " << getName() << ": cannot do anything to " << target << " due to a lack of hitpoint" << std::endl;
        return ;
    }
    if (getEnergyPoint() == 0) {
        std::cout << "ClapTrap " << getName() << ": cannot do anything to " << target << "due to a lack of energypoint" << std::endl;
        return ;
    }
    setEnergyPoint(getEnergyPoint() - 1);
    std::cout << "ClapTrap " << getName() << ": attacks " << target << " causing " << getAttackDamage() << " points of damages!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (getHitPoint() == 0) {
        std::cout << "ClapTrap " << getName() << ": already destroyed" << std::endl;
        return ;
    }
    if (amount >= getHitPoint())
        setHitPoint(0);
    else
        setHitPoint(getHitPoint() - amount);
    std::cout << "ClapTrap " << getName() << ": gets " << amount << " damages, remaining: " << getHitPoint() << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (getHitPoint() == 0) {
        std::cout << "ClapTrap " << getName() << ": cannot be repaired due to a lack of hitpoint" << std::endl;
        return ;
    }
    if (getEnergyPoint() == 0) {
        std::cout << "ClapTrap " << getName() << ": cannot do be repaired due to a lack of energypoint" << std::endl;
        return ;
    }
    setEnergyPoint(getEnergyPoint() - 1);
    setHitPoint(getHitPoint() + amount);
    std::cout << "ClapTrap " << getName() << ": repairs itself for " << amount << " hps" << std::endl;
}
