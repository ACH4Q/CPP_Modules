#include <iostream>

int main()
{
    std::string mystr =  "HI THIS IS BRAIN";
    std::string& refstr = mystr;
    std::string* ptrstr = &mystr;

    std::cout << "Adress" << std::endl;
    std::cout << &mystr << std::endl;
    std::cout << &ptrstr << std::endl;
    std::cout << &refstr <<std::endl;

    std::cout << "value" << std::endl;
    std::cout << mystr << std::endl;
    std::cout << ptrstr << std::endl;
    std::cout << refstr <<std::endl;

}