#include "Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; ++i)
    {
        this->_inventory[i] = 0;
    }
}

Character::Character(const Character &src)
{
    this->_name = src._name;
    for (int i = 0; i < 4; i++)
    {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = 0;
    }
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
        delete this->_inventory[i];
    }
}

Character& Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
        {
            delete this->_inventory[i];
            this->_inventory[i] = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

std::string const & Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; ++i)
    {
        if (!this->_inventory[i])
        {
            this->_inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int id)
{
    if (id >= 0 && id < 4)
    {
        this->_inventory[id] = 0;
    }
}

void Character::use(int id, ICharacter& target)
{
    if (id >= 0 && id < 4 && this->_inventory[id])
    {
        this->_inventory[id]->use(target);
    }
}