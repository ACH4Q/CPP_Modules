#include "Zombie.hpp"
Zombie* zombieHorde(int N, std::string name)
{
    if (N < 0)
    {
        std::cerr << "number is negative" << std::endl;
        return 0;
    }
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
        horde[i].setname(name);
    return horde;
}