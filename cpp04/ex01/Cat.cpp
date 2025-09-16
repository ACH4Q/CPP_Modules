#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    this->brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Assignment Operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*(other.brain));
    }
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}


Brain* Cat::getBrain() const
{
    return this->brain;
}