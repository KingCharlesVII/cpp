#include <iostream>
#include <string>

class Weapon {
    private:
        std::string type;

    public:
        Weapon(const std::string& type);
        const std::string& getType(void) const;
        void    setType(const std::string& newType);
};

Weapon::Weapon(const std::string& type) : type(type) {

}

const std::string& Weapon::getType(void) const {
    return (type);
}

void    Weapon::setType(const std::string &newType) {
    type = newType;
}

class HumanA {
    private:
        std::string name;
        Weapon& weapon;
    public:
        HumanA(const std::string& name, Weapon& weapon);
        void    attack() const;
};

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {

}

void    HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

class HumanB {
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(const std::string& name);
        void setWeapon(Weapon& weapon);
        void    attack() const;
};

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {

}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void    HumanB::attack() const {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon" << std::endl;
}

int main()
{
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}
{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.setWeapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}
return 0;
}