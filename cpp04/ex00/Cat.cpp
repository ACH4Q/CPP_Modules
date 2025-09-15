#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat &other)
{
    *this = other;
    std::cout << "copy costructor called for Cat" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    this->type = other.type;
    std::cout << "coppy assaniment called for Cat" << std::endl;
}

Cat::~Cat() {}

void Cat::makeSound() const
{
    std::cout << "haw haw" << std::endl;
}