#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>


Base * generate(void)
{
    int random = std::rand() % 3;

    if (random == 0)
        return (new A());
    else if (random == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(const std::bad_cast& e) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cout << "C" << std::endl;
    }
}

int main()
{
    std::srand(std::time(0));

	Base* my_object = generate();

	std::cout << "Identify by pointer: ";
	identify(my_object);

	std::cout << "Identify by reference: ";
	identify(*my_object);

	delete my_object;

	return 0;
}