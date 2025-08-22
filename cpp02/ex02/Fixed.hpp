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
    Fixed operator-(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

	bool			operator==(const Fixed &F) const;
	bool			operator>=(const Fixed &F) const;
	bool			operator<=(const Fixed &F) const;
	bool			operator!=(const Fixed &F) const;
	bool			operator<(const Fixed &F) const;
	bool			operator>(const Fixed &F) const;

	Fixed			operator++(int);
	Fixed			operator--(int);
	Fixed&			operator++();
	Fixed&			operator--();

	static Fixed&			min(Fixed& F1, Fixed& F2);
	static const Fixed&		min(const Fixed& F1, const Fixed& F2);
	static Fixed&			max(Fixed& F1, Fixed& F2);
	static const Fixed&		max(const Fixed& F1, const Fixed& F2);

    ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif