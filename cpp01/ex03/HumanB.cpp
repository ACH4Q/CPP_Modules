#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->weapon  = NULL;
	this->name = name;
}
void HumanB::attack()
{
	if(weapon == NULL)
	{
		std::cout << "does not support\n";
		return ;
	}
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

HumanB::~HumanB()
{

}