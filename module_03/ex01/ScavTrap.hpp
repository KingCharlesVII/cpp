#pragma once

#include <iostream>
#include <string>

class ScavTrap: public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& other);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& other);
        void    attack(const std::string& target);
        void    guardGate(void);
        bool    getGuardingState();
        void    setGuardingState(bool guarding_state);
    private:
        bool is_guarding_gate;
};