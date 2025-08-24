#include "Point.hpp"

Point::Point() : point_x(0) , point_y(0) {}

Point::~Point() {}

Point::Point(float fl_x, float fl_y) : point_x(fl_y) , point_y(fl_y) {}

Point::Point(const Point& copy) : point_x(0) , point_y(0)
{
    *this = copy;
}
Point &Point::operator=(const Point& other)
{
    (void)other;
    return (*this);
}


Fixed Point::getX() const
{
    return point_x;
}

Fixed Point::getY() const
{
    return point_y;
}

Fixed Point::area(Point const p1, Point const p2, Point const p3)
{
    
    Fixed result = std::abs((p1.getX() * (p2.getY() - p3.getY()) + 
                           p2.getX() * (p3.getY() - p1.getY()) + 
                           p3.getX() * (p1.getY() - p2.getY())).toFloat()) / 2.0f;
    
    return result;
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point) 
{
    Fixed areaABC = Point::area(a, b, c);
    Fixed areaPAB = Point::area(point, a, b);
    Fixed areaPBC = Point::area(point, b, c);
    Fixed areaPCA = Point::area(point, c, a);

    return (areaABC == (areaPAB + areaPBC + areaPCA));
}