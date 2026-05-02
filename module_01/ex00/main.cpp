#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;
    public:
        void announce(void);
        Zombie(const std::string);
        ~Zombie();
};

Zombie  *newZombie(std::string zombie_name);
void    randomChump(std::string name);

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
