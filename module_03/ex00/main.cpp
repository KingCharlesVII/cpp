/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:29:04 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 10:29:05 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main(void) {
    const std::string clap_1_name("Clap1");
    const std::string clap_2_name("Clap2");
    ClapTrap    clap1(clap_1_name);
    ClapTrap    clap2(clap_2_name);

    clap1.setAttackDamage(5);
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap2.beRepaired(7);
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());

    ClapTrap clap3 = clap1;
    clap3.setName("Clap3");
    clap3.setAttackDamage(30);
    clap3.attack(clap1.getName());
    clap1.takeDamage(clap3.getAttackDamage());
    clap3.attack(clap1.getName());
    clap1.takeDamage(clap3.getAttackDamage());
}
