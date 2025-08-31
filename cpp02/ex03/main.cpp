#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(5, 5);

    Point insidePoint(3.8, 2);

    Point outsidePoint(40, 40);

    Point testPoint;

    if (bsp(a, b, c, insidePoint)) 
        std::cout << "Inside point test: PASSED" << std::endl;
    else 
        std::cout << "Inside point test: FAILED" << std::endl;

    if (!bsp(a, b, c, outsidePoint))
        std::cout << "Outside point test: PASSED" << std::endl;
    else
        std::cout << "Outside point test: FAILED" << std::endl;
}