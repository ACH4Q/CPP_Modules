#include "Zombie.hpp"


Zombie::Zombie() 
{
}

Zombie::~Zombie()
{
    std::cout << name << " Destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string name)
{
    this->name = name;
}