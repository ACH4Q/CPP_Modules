#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iomanip>

class ScalarConverter
{
private:
    ScalarConverter(std::string name);
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter operator=(const ScalarConverter& other);
    ~ScalarConverter();
public:
    static void convert(const std::string& target);
    class ConvertExeption : public std::exception
    {
        public:
            const char* what() const throw();
    };
 
};

#endif