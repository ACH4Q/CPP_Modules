#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Testing Vector " << std::endl;
    try {
        easyfind(vec, 20);
        easyfind(vec, 42);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    std::cout << "\nTesting List" << std::endl;
    try {
        easyfind(lst, 3);
        easyfind(lst, 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}