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
        unsigned int getEnergyPoint(void) const;
        unsigned int getAttackDamage(void) const;
        unsigned int getHitPoint(void) const;
};

ClapTrap::ClapTrap() {
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
    this->name = name;
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

unsigned int ClapTrap::getEnergyPoint(void) const {
    return (this->energyPoint);
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return (this->attackDamage);
}

unsigned int ClapTrap::getHitPoint(void) const {
    return (this->hitPoint);
}

void    ClapTrap::beRepaired(unsigned int amount) {
    this->setHitPoint(this->getHitPoint() + amount);
}

int main(void) {

}