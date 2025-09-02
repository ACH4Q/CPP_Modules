#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Def") , hit(10) , point(10), _attack(0) {}

ClapTrap::~ClapTrap()
{
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    *this = copy;
}