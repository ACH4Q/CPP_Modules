#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "Default Constructor Calles for WrongCat" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Coppy Assgnement Called for WrongCat" << std::endl;
    return *this;
}

WrongCat::WrongCat(const WrongCat& other)
{
    *this = other;
    std::cout << "Copy Constructor Called For WrongCat" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor Called For WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Some Cat Sound meow meow" << std::endl;
}