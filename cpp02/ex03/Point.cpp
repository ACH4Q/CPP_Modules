#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{ 
    (void)other; 
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const 
{ 
    return x; 
}
Fixed Point::getY() const 
{ 
    return y; 
}

static Fixed area(Point a, Point b, Point c)
{
    return (a.getX()*(b.getY()-c.getY()) + 
            b.getX()*(c.getY()-a.getY()) + 
            c.getX()*(a.getY()-b.getY())) / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    Fixed abc = area(a, b, c);
    Fixed pab = area(point, a, b);
    Fixed pbc = area(point, b, c);
    Fixed pca = area(point, c, a);
    
    if (pab == Fixed(0) || pbc == Fixed(0) || pca == Fixed(0))
        return false;
        
    return (pab + pbc + pca) == abc;
}