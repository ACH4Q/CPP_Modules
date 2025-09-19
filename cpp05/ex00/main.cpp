#include "Bureaucrat.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "TESTING" << std::endl;
	try
	{
		Bureaucrat b1("test", 2);
		std::cout << b1 << std::endl;
		b1.DecrementGrade();
		std::cout << "After increment: " << b1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	return (0);
}