#include "Fixed.hpp"


Fixed::Fixed() : Fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "destructor called" << std::endl;
}


Fixed &Fixed::operator=(const Fixed &others)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &others)
    {
        this->Fixed_point= others.Fixed_point;
    }
    return *this;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy; 
}

void Fixed::setRawBits( int const raw )
{
    this->Fixed_point = raw;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->Fixed_point);
}