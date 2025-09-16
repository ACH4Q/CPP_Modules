#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Constructor Called For Brain" << std::endl;
}
Brain::Brain(const Brain& other)
{
    std::cout << "Copy Constructor Called For Brain" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copy Assignement Called For Brain" << std::endl;
    if (this != & other)
    {
        for (size_t i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Default Destructor Called For Brain" << std::endl;
}