#include "ScavTrap.hpp"

bool    ScavTrap::getGuardingState() const {
    return is_guarding_gate;
}
ScavTrap::ScavTrap(): ClapTrap(), is_guarding_gate(false) {
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " constructed by default" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name), is_guarding_gate(false) {
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " conctructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other), is_guarding_gate(false) {
    (void)other;
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " conctructed" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << getName() << " destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        setHitPoint(other.getHitPoint());
        setEnergyPoint(other.getEnergyPoint());
        setAttackDamage(other.getAttackDamage());
        setName(other.getName());
    }
    return (*this);
}

void    ScavTrap::attack(const std::string& target) {
    if (getHitPoint() == 0) {
        std::cout << "Scavtrap " << getName() << " Cannot attack due to a lack of hitpoint" << std::endl;
        return ;
    }
    if (getEnergyPoint() == 0) {
        std::cout << "ScavTrap " << getName() << "cannot attack." << std::endl;
        return ;
    }
    setEnergyPoint(getEnergyPoint() - 1);
    std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damages!" << std::endl;
}

void    ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << getName() << " is now keeping the gate." << std::endl;
}