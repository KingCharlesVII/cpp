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
        ClapTrap(std::string name);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setEnergyPoint(unsigned int energyPoint);
        void setAttackDamage(unsigned int attackDamage);
        void setHitPoint(unsigned int hitPoint);
        std::string getName(void) const;
        unsigned int getEnergyPoint(void) const;
        unsigned int getAttackDamage(void) const;
        unsigned int getHitPoint(void) const;
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

unsigned int ClapTrap::getEnergyPoint(void) const {
    return (this->energyPoint);
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return (this->attackDamage);
}

unsigned int ClapTrap::getHitPoint(void) const {
    return (this->hitPoint);
}

std::string ClapTrap::getName(void) const {
    return (this->name);
}

ClapTrap::ClapTrap() {
    this->name = "Default";
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap " << this->getName() << " constructed by default." << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
    this->name = name;
    std::cout << "Clap trap " << this->getName() << " contructed" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " destroyed." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->getEnergyPoint() == 0) {
        std::cout << "Cannot be repaired due to a lack of energy points." << std::endl;
        return ;
    }
    if (this->getHitPoint() == 0) {
        std::cout << "Cannot be repaired due to a lack of hitpoint." << std::endl;
        return ;
    }
    this->setEnergyPoint(this->getEnergyPoint() - 1);
    this->setHitPoint(this->getHitPoint() + amount);
    std::cout << "ClapTrap " << this->getName() << " repairs itself for " << amount << " hps." << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (this->getHitPoint() == 0) {
        std::cout << "ClapTrap " << this->getName() << " is already destroyed" << std::endl;
        return ;
    }
    if (amount >= this->getHitPoint())
        this->setHitPoint(0);
    else
        this->setHitPoint(this->getHitPoint() - amount);
    std::cout << "ClapTrap " << this->getName() << " gets " << amount << " damages, remaining: " << this->getHitPoint() <<  std::endl;
}

void    ClapTrap::attack(const std::string& target) {
    if (this->getHitPoint() == 0) {
        std::cout << "Cannot attack due to a lack of hitpoint" << std::endl;
        return ;
    }
    if (this->getEnergyPoint() == 0) {
        std::cout << "ClapTrap " << this->getName() << "cannot attack." << std::endl;
        return ;
    }
    this->setEnergyPoint(this->getEnergyPoint() - 1);
    std::cout << "ClapTrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << " points of damages!" << std::endl;
}

int main(void) {

}