#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;
    public:
        void announce(void);
        void setName(const std::string& name);
        Zombie();
        Zombie(const std::string&);
        ~Zombie();
};

Zombie  *newZombie(std::string zombie_name);
Zombie  *zombieHorde(int N, const std::string& name);
void    randomChump(std::string name);

Zombie::Zombie() {
    
}

void    Zombie::setName(const std::string& name) {
    this->name = name;    
}

Zombie  *zombieHorde(size_t N, const std::string& name) {
    if (N <= 0)
        return (NULL);
    Zombie  *zombie_horde = new Zombie[N];
    for (size_t i =0; i< N; i++) {
        zombie_horde[i].setName(name);
    }
    return (zombie_horde);
}


Zombie::Zombie(const std::string& zombie_name): name(zombie_name) {
    
}
   
Zombie::~Zombie() {
    std::cout << this->name << " destroyed" << std::endl;
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

   size_t N = 5;
   Zombie *horde = zombieHorde(N, "Horde");
   for (size_t i = 0; i < N; i++) {
    horde[i].announce();
    }
delete[] horde;
    return 0;
}
