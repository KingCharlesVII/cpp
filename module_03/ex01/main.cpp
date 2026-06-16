/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:48:25 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 10:48:28 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void) {
    ScavTrap s1("S1");
    ScavTrap s2("S2");

    s2.attack(s1.getName());
    s1.takeDamage(s2.getAttackDamage());
    s2.setAttackDamage(80);
    s1.takeDamage(s2.getAttackDamage());
    s2.setAttackDamage(80);
    s1.takeDamage(s2.getAttackDamage());
    s2.setGuardingState(true);
    s2.guardGate();
    s1.guardGate();

    ScavTrap s3(s2);
    s3.setName("S3");
    s3.guardGate();
}