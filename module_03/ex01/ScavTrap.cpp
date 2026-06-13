/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:48:08 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 10:48:09 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(), is_guarding_gate(false) {
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << ": call the default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name), is_guarding_gate(false) {
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << ": call te overloaded constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
    std::cout << "ScavTrap " << getName() << ": call the copy constructor" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << getName() << ": destroy" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        setGuardingState(other.getGuardingState());
    }
    return (*this);
}

void    ScavTrap::attack(const std::string& target) {
    if (getHitPoint() == 0) {
        std::cout << "ScavTrap " << getName() << ": cannot do anything to " << target << " due to a lack of hitpoint" << std::endl;
        return ;
    }
    if (getEnergyPoint() == 0) {
        std::cout << "ScavTrap " << getName() << ": cannot do anything to " << target << "due to a lack of energypoint" << std::endl;
        return ;
    }
    setEnergyPoint(getEnergyPoint() - 1);
    std::cout << "ScavTrap " << getName() << ": attacks " << target << " causing " << getAttackDamage() << " points of damages!" << std::endl;
}

bool ScavTrap::getGuardingState() const {
    return is_guarding_gate;
}

void    ScavTrap::setGuardingState(bool guarding_state) {
    is_guarding_gate = guarding_state;
}

void    ScavTrap::guardGate() {
    if (getHitPoint() == 0) {
        std::cout << "ScavTrap " << getName() << ": cannot keep the gate for it is already destroyed" << std::endl;
        return ;
    }
    if (getGuardingState()) {
        std::cout << "ScavTrap " << getName() << ": already keeping the gate" << std::endl;
        return ;
    }
    setGuardingState(true);
    std::cout << "ScavTrap " << getName() << ": keep the gate" << std::endl;
}
