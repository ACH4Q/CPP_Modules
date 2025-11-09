#include "ScalarConverter.hpp"

int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error Cannot convert " << std::endl;
        std::cerr << "Usage ./converter (argument)" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
}

