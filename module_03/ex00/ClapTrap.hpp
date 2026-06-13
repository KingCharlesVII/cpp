/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:28:53 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 10:28:56 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap {
    private:
        std::string name;
        unsigned int hitPoint;
        unsigned int energyPoint;
        unsigned int attackDamage;
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void setEnergyPoint(unsigned int energyPoint);
        void setAttackDamage(unsigned int attackDamage);
        void setHitPoint(unsigned int hitPoint);
        void setName(const std::string& name);

        const std::string& getName() const;
        unsigned int getEnergyPoint() const;
        unsigned int getAttackDamage() const;
        unsigned int getHitPoint() const;
};
