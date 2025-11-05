#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
    
public:
    static void convert(const std::string& str);
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter operator=(const ScalarConverter& other);
    ~ScalarConverter();
};

#endif