#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScravTrap : public ClapTrap
{

public:

    ScravTrap();
    ScravTrap(std::string _name);
    ScravTrap(const ScravTrap& other);
    ScravTrap& operator=(const ScravTrap& other);
    ~ScravTrap();
    void attack(const std::string& target);
    void guardGate();
};


#endif