#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

    Fixed getX() const;
    Fixed getY() const;
    Fixed area(Point const p1, Point const p2, Point const p3);
    bool bsp( Point const a, Point const b, Point const c, Point const point);
};


#endif