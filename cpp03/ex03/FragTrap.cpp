#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{  
    name = "Default";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default constructor called for " << name << std::endl;

}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    name = _name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "FragTrap Parameterized constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    if (this != &other)
    {
        *this = other;
        std::cout << "FragTrap Copy constructor called for " << name << std::endl;
    }
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "FragTrap Copy assignment operator called for " << name << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called for " << name << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "requests a high five! Give me five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{ 
    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "ScarvTrap " << name << " can't attack. Not enough energy or hit points." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScarvTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}