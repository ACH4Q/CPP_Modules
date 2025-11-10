#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>




class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(const std::string& literal);
};

#endif
