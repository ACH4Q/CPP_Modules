#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Animal")
{
    std::cout << "Default Constructor Called For WrongAnimal" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Coppy asignement called for WrongAnimal" << std::endl;
    return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    *this = other;
    std::cout << "Copy Constructor Called For WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor Called for WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "Some Animal Sound ..." << std::endl;
}
