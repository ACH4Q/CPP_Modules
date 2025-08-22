#include "Point.hpp"

Point::Point() : point_x(0) , point_y(0) {}

Point::~Point() {}

Point::Point(float fl_x, float fl_y) : point_x(fl_y) ,  point_y(fl_y) {}

Point::Point(const Point& copy) : point_x(0) , point_y(0)
{
    *this = copy;
}

Point &Point::operator=(const Point& other)
{
    return (*this);
}

