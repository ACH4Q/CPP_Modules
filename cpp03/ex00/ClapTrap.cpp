#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : name(_name), hitPoints(10), energyPoints(10), attackDamage(0)
{ 
    std::cout << "ClapTrap Parameterized constructor called for " << _name << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap Copy constructor called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap Copy assignment operator called for " << name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't attack. Not enough energy or hit points." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }
    if (hitPoints < amount) 
    { 
        hitPoints = 0;
    } else
    {
        hitPoints -= amount;
    }
    std::cout << "ClapTrap " << name << " took " << amount << " damage, " << hitPoints << " hit points remaining." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{

    if (energyPoints == 0 || hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't be repaired. Not enough energy or already destroyed." << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repaired itself for " << amount << " hit points, " << hitPoints << " hit points remaining." << std::endl;
}