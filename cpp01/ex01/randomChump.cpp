#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie randomChump;
    randomChump.setname(name);
    randomChump.announce();
}