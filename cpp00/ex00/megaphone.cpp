#include <iostream>
#include <cctype> 
#include <string>

void printUppercase(const std::string& str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        std::cout << (char)std::toupper(str[i]);
    }
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    
    for (int i = 1; i < ac; ++i)
    {
        printUppercase(av[i]);
        if (i < ac - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}