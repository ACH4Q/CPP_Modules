#include "ClapTrap.hpp"

int main()
{
    ClapTrap clappy("Clappy");
    ClapTrap trappy("Trappy");

    clappy.attack("Trappy");
    trappy.takeDamage(4);
    trappy.beRepaired(-5);

    trappy.attack("Clappy");
    clappy.takeDamage(0);

    return 0;
}