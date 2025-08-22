#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
private:

    Fixed const point_x;
    Fixed const point_y;

public:

    Point();
    Point(const Point& other);
    Point& operator=(const Point& other);
    Point(float fl_x, float fl_y);
    ~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif