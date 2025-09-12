#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    FragTrap::hitPoints = 100;   
    ScavTrap::energyPoints = 50; 
    FragTrap::attackDamage = 30; 
    std::cout << "DiamondTrap Parameterized constructor called for " << name << std::endl;
}


DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called for " << name << std::endl;
}


void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}


DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default") {}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}