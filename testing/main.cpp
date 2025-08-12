#include <iostream>

int main()
{
    int k = 0;
    int j = 10;
    int l = 9;
    for (int i = 1; i < 20 ; ++i)
    {
        k -= j * l;
        k++;
        std::cout << k << std::endl;
    }
    std::cout << "testing" << std::endl;
}