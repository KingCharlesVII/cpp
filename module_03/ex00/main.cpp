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

ClapTrap::ClapTrap(): name("Default"), hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << "ClapTrap " << getName() << " constructed by default" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): name(name), hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << "Clap trap " << getName() << " contructed" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << getName() << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): name(other.getName()), hitPoint(other.getHitPoint()), energyPoint(other.getEnergyPoint()), attackDamage(other.getAttackDamage()) {
    std::cout << "ClapTrap " << getName() <<"copy contructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap " << getName() << " assignement operator called" << std::endl;
    if (this != &other) {
        setName(other.getName());
        setHitPoint(other.getHitPoint());
        setEnergyPoint(other.getEnergyPoint());
        setAttackDamage(other.getAttackDamage());
    }
    return (*this);
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (getEnergyPoint() == 0) {
        std::cout << "ClapTrap " << getName() << " cannot be repaired due to a lack of energy points" << std::endl;
        return ;
    }
    if (getHitPoint() == 0) {
        std::cout << "ClapTrap " << getName() << " cannot be repaired due to a lack of hitpoint" << std::endl;
        return ;
    }
    setEnergyPoint(this->getEnergyPoint() - 1);
    setHitPoint(this->getHitPoint() + amount);
    std::cout << "ClapTrap " << getName() << " repairs itself for " << amount << " hps." << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (getHitPoint() == 0) {
        std::cout << "ClapTrap " << this->getName() << " is already destroyed" << std::endl;
        return ;
    }
    if (amount >= getHitPoint())
        setHitPoint(0);
    else
        setHitPoint(getHitPoint() - amount);
    std::cout << "ClapTrap " << getName() << " gets " << amount << " damages, remaining: " << getHitPoint() << std::endl;
}

void    ClapTrap::attack(const std::string& target) {
    if (getHitPoint() == 0) {
        std::cout << "ClapTrap " << getName() << "cannot attack " << target << "due to a lack of hitpoint" << std::endl;
        return ;
    }
    if (this->getEnergyPoint() == 0) {
        std::cout << "ClapTrap " << getName() << "cannot attack " << target << std::endl;
        return ;
    }
    setEnergyPoint(getEnergyPoint() - 1);
    std::cout << "ClapTrap " << this->getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damages!" << std::endl;
}

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

int main(void) {

}