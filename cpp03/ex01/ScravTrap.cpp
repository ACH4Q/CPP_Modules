#include "ScravTrap.hpp"

ScravTrap::ScravTrap() : ClapTrap()
{  
    name = "Default";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScravTrap Default constructor called for " << name << std::endl;

}

ScravTrap::ScravTrap(std::string _name) : ClapTrap(_name)
{
    name = _name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScravTrap Parameterized constructor called for " << _name << std::endl;
}

ScravTrap::ScravTrap(const ScravTrap& other) : ClapTrap(other)
{
    if (this != &other)
    {
        *this = other;
        std::cout << "ScravTrap Copy constructor called for " << name << std::endl;
    }
}

ScravTrap& ScravTrap::operator=(const ScravTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ScravTrap Copy assignment operator called for " << name << std::endl;
    return *this;
}

ScravTrap::~ScravTrap()
{
    std::cout << "ScravTrap Destructor called for " << name << std::endl;
}

void ScravTrap::guardGate()
{
    std::cout << "ScravTrap is now in Gatekeeper mode" << std::endl;
}

void ScravTrap::attack(const std::string& target)
{ 
    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "ScarvTrap " << name << " can't attack. Not enough energy or hit points." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScarvTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}