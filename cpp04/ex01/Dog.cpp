#include "Dog.hpp"

Dog::Dog()
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->brain = new Brain(*(other.brain));
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*(other.brain));
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}


Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Some Dog sound..." << std::endl;
}