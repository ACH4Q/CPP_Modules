#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>  
#include <iostream>   
#include <stdexcept> 

template<typename T>
void easyfind(T &obj, int i)
{ 
    typename T::iterator it = std::find(obj.begin(), obj.end(), i);

    if (it != obj.end())
    {
        std::cout << "Element found: " << *it << std::endl;
    }
    else
    {
        throw std::runtime_error("Element not found");
    }
}

#endif