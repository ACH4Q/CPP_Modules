#include "ScalarConverter.hpp"
#include <iostream>

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
        std::cout << "char impossbile" << std::endl;
        std::cout << "int impossible" << std::endl;
        std::cout << "float convertion " << static_cast<float>(doub) << std::endl;
        std:: cout << "double convertion " << doub << std::endl;
    }

    char *end = NULL;
    double dnull = std::strtod(target.c_str() , &end); 

    if (!(target.length() == 1) || target == "f" && target.c_str())
    {
        std::cout << "char impossbile" << std::endl;
        std::cout << "int impossible" << std::endl;
        std::cout << "float impossible" << std::endl;
    }
    double d;
    static_cast<char>(d);
    
}

