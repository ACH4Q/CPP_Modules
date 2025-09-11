#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{  
    name = "Default";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Default constructor called for " << name << std::endl;

}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    name = _name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Parameterized constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    if (this != &other)
    {
        *this = other;
        std::cout << "ScavTrap Copy constructor called for " << name << std::endl;
    }
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ScavTrap Copy assignment operator called for " << name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called for " << name << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{ 
    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "ScarvTrap " << name << " can't attack. Not enough energy or hit points." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScarvTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}