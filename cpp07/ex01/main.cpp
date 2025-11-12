#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void printElement(const T &element)
{
    std::cout << element << std::endl;
}

void increment(int &num)
{
    num++;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    int len_numbers = 5;

    std::cout << "--- Non-const int array ---" << std::endl;
    iter(numbers, len_numbers, printElement<int>);
    
    iter(numbers, len_numbers, increment);
    
    std::cout << "\n--- After incrementing ---" << std::endl;
    iter(numbers, len_numbers, printElement<int>);

    const std::string words[] = {"alpha", "beta", "gamma"};
    int len_words = 3;

    std::cout << "\n--- Const string array ---" << std::endl;
    iter(words, len_words, printElement<std::string>);

    return 0;
}