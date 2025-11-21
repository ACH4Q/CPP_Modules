#include "BitcoinExchange.hpp"

int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cerr << "error" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.processInputFile(av[1]);
    return 0;
}