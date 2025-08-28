#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : Fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}


Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    this->Fixed_point = integer << fraction;
}

Fixed::Fixed(const float fl)
{
    std::cout << "Float constructor called" << std::endl;
    this->Fixed_point = roundf(fl * (1 << fraction));
}

Fixed &Fixed::operator=(const Fixed &others)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &others) {
        this->Fixed_point = others.Fixed_point;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->Fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this->Fixed_point = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->Fixed_point / (1 << fraction);
}

int Fixed::toInt(void) const
{
    return this->Fixed_point >> fraction;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return(Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return(Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return(Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return(Fixed(toFloat() / other.toFloat()));
}

bool			Fixed::operator==(const Fixed &F) const
{
    return (Fixed_point == F.Fixed_point);
}

bool			Fixed::operator>=(const Fixed &F) const
{
    return (Fixed_point >= F.Fixed_point);
}

bool			Fixed::operator<=(const Fixed &F) const
{
    return (Fixed_point <= F.Fixed_point);
}

bool			Fixed::operator!=(const Fixed &F) const
{
    return (Fixed_point != F.Fixed_point);
}

bool			Fixed::operator<(const Fixed &F) const
{
    return (Fixed_point < F.Fixed_point);
}

bool			Fixed::operator>(const Fixed &F) const
{
    return (Fixed_point > F.Fixed_point);
}

Fixed			Fixed::operator++(int)
{
    Fixed tmp = *this;
    Fixed_point++;
    return(tmp);
}

Fixed			Fixed::operator--(int)
{
    Fixed tmp = *this;
    Fixed_point--;
    return(tmp);
}

Fixed&			Fixed::operator++()
{
    Fixed_point++;
    return(*this);
}

Fixed&			Fixed::operator--()
{
    Fixed_point--;
    return(*this);
}

Fixed& Fixed::min(Fixed& F1, Fixed& F2) {
    if (F1 < F2)
        return F1;
    else
        return F2;
}

const Fixed& Fixed::min(const Fixed& F1, const Fixed& F2) {
    if (F1 < F2)
        return F1;
    else
        return F2;
}

Fixed& Fixed::max(Fixed& F1, Fixed& F2) {
    if (F1 > F2)
        return F1;
    else
        return F2;
}

const Fixed& Fixed::max(const Fixed& F1, const Fixed& F2) {
    if (F1 > F2)
        return F1;
    else
        return F2;
}