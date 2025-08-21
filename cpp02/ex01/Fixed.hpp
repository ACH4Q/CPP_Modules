#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int Fixed_point;
    static const int fraction = 8;
public:
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    Fixed();
    Fixed(const Fixed& copy);
    Fixed(const int);
    Fixed(const float fl);
    Fixed& operator=(const Fixed &other);
    ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif