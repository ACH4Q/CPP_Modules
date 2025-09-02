#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>


class ClapTrap
{
private:
    std::string name;
    int hit;
    int point;
    int _attack;
public:

    ClapTrap();
    ClapTrap(std::string _name, int _hit, int _point, int _attack);
    ClapTrap(const ClapTrap& copy);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};



#endif