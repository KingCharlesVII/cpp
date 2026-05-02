#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;
    public:
        void announce(void);
        void setName(std::string name);
        Zombie();
        Zombie(const std::string);
        ~Zombie();
};

Zombie  *newZombie(std::string zombie_name);
Zombie  *zombieHorde(int N, std::string name);
void    randomChump(std::string name);

Zombie::Zombie() {
    
}

void    Zombie::setName(std::string name) {
    this->name = name;    
}

Zombie  *zombieHorde(int N, std::string) {
    if (N <= 0)
        return (nullptr);
    Zombie  *zombie_horde = new Zombie[N];
    for (int i =0; i< N; i++) {
        zombie_horde[i].setName("Zobmie_" + std::to_string(i));
    }
    return (zombie_horde);
}


Zombie::Zombie(const std::string zombie_name): name(zombie_name) {
    
}

Zombie::~Zombie() {
    std::cout << this->name << " is deleted" << std::endl;
}

void    Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;    
}

Zombie  *newZombie(std::string name) {
    return (new Zombie(name));
}

void    randomChump(std::string name) {
    Zombie local_zombie(name);
    local_zombie.announce();
}

int main()
{
    std::string zombie_name = "zzz";
   Zombie *zombie = newZombie(zombie_name);
   zombie->announce();
   delete zombie;
   randomChump("StackZombie");
    return 0;
}
