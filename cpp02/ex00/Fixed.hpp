#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int Fixed_point;
    static const int fraction = 8;
public:
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    Fixed();
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed &other);
    ~Fixed();
};

#endif