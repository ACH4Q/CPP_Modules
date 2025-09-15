#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog &other)
{
    *this = other;
    std::cout << "copy costructor called for Dog" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    this->type = other.type;
    std::cout << "coppy assaniment called for Dog" << std::endl;
}

Dog::~Dog() {}

void Dog::makeSound() const
{
    std::cout << "haw haw" << std::endl;
}