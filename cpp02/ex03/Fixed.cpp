#include "Fixed.hpp"

Fixed::Fixed() : Fixed_point(0) {}

Fixed::Fixed(const Fixed& copy) 
{
     *this = copy; 
}

Fixed::Fixed(const int integer)
{ 
    Fixed_point = integer << fraction; 
}

Fixed::Fixed(const float fl) 
{ 
    Fixed_point = roundf(fl * (1 << fraction)); 
}

Fixed& Fixed::operator=(const Fixed &others) 
{
    if (this != &others) Fixed_point = others.Fixed_point;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const 
{ 
    return Fixed_point; 
}

void Fixed::setRawBits(int const raw)
{ 
    Fixed_point = raw; 
}

float Fixed::toFloat(void) const 
{ 
    return (float)Fixed_point / (1 << fraction);
}

int Fixed::toInt(void) const 
{ 
    return Fixed_point >> fraction; 
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 
{
    os << fixed.toFloat();
    return os;
}

Fixed Fixed::operator-(const Fixed &other) const 
{ 
    return Fixed(toFloat() - other.toFloat()); 
}
Fixed Fixed::operator+(const Fixed &other) const 
{ 
    return Fixed(toFloat() + other.toFloat()); 
}
Fixed Fixed::operator*(const Fixed &other) const 
{ 
    return Fixed(toFloat() * other.toFloat()); 
}
Fixed Fixed::operator/(const Fixed &other) const 
{ 
    return Fixed(toFloat() / other.toFloat()); 
}

bool Fixed::operator==(const Fixed &F) const 
{ 
    return Fixed_point == F.Fixed_point; 
}
bool Fixed::operator>=(const Fixed &F) const 
{ 
    return Fixed_point >= F.Fixed_point; 
}
bool Fixed::operator<=(const Fixed &F) const 
{ 
    return Fixed_point <= F.Fixed_point; 
}
bool Fixed::operator!=(const Fixed &F) const 
{ 
    return Fixed_point != F.Fixed_point; 
}
bool Fixed::operator<(const Fixed &F) const 
{ 
    return Fixed_point < F.Fixed_point;
}
bool Fixed::operator>(const Fixed &F) const 
{ 
    return Fixed_point > F.Fixed_point; 
}

Fixed Fixed::operator++(int) 
{ 
    Fixed tmp(*this); 
    Fixed_point += 1; 
    return tmp; 
}

Fixed Fixed::operator--(int) 
{ 
    Fixed tmp(*this); 
    Fixed_point -= 1; 
    return tmp; 
}

Fixed& Fixed::operator++() 
{ 
    Fixed_point += 1; return *this; 
}

Fixed& Fixed::operator--() 
{ 
    Fixed_point -= 1; return *this; 
}

Fixed& Fixed::min(Fixed& F1, Fixed& F2) 
{ 
    return (F1 < F2) ? F1 : F2; 
}
const Fixed& Fixed::min(const Fixed& F1, const Fixed& F2) 
{ 
    return (F1 < F2) ? F1 : F2; 
}
Fixed& Fixed::max(Fixed& F1, Fixed& F2) 
{ 
    return (F1 > F2) ? F1 : F2;
}
const Fixed& Fixed::max(const Fixed& F1, const Fixed& F2) 
{ 
    return (F1 > F2) ? F1 : F2; 
}