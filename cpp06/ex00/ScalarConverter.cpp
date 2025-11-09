#include "ScalarConverter.hpp"
#include <iostream>
#include <cmath>
#include <climits>

const char* ScalarConverter::ConvertExeption::what() const throw()
{
    std::cerr << "Cannot convert" << std::endl;
    return NULL;
}

void ScalarConverter::convert(const std::string& target)
{
    if (target == "-inf" || target == "+inf" || target == "+inff" || target == "-inff" || target == "nanf" || target == "nan")
    {
        double doub = std::strtod(target.c_str(),NULL);
        std::cout << "char convertion is impossbile" << std::endl;
        std::cout << "int convertion is impossible" << std::endl;
        std::cout << "float convertion is " << static_cast<float>(doub) << std::endl;
        std:: cout << "double convertion is " << doub << std::endl;
    }

    char *end = NULL;
    double dnull = std::strtod(target.c_str() , &end); 

    if (!(target.c_str() && target.length() != 1) || (*end && std::string(end) != "f"))
    {
        std::cout << "char convertion is impossbile" << std::endl;
        std::cout << "int convertion is impossible" << std::endl;
        std::cout << "float convertion is impossible" << std::endl;
    }
    if (target.length() == 1 && !std::isdigit(target[0]))
    {
        dnull = static_cast<double>(target[0]);
    }
    if (std::isnan(dnull) || std::isinf(dnull) || dnull < 0 || dnull > 127)
    {
        std::cout << "impossbile" << std::endl;
    }
    else if (!isprint(static_cast<char>(dnull)))
    {
        std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "'" << static_cast<char>(dnull )<< "'" << std::endl;    
    
    std::cout << "int convertion is";

    if (std::isnan(dnull) || std::isinf(dnull) || dnull < std::numeric_limits<int>::min() || dnull > std::numeric_limits<int>::max())
        std::cout << "impossbile" << std::endl;
    else
        std::cout << static_cast<int>(dnull) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float convertion is " << std::endl;
    std::cout << "double conversion is" << std::endl;
}

