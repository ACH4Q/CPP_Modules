#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "--- Subject's Example Test ---" << std::endl;
    Span sp = Span(5);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    std::cout << "\n--- Exception Tests ---" << std::endl;
    std::cout << "Testing adding to a full Span:" << std::endl;
    try
    {
        sp.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught expected error: " << e.what() << '\n';
    }

    std::cout << "\nTesting finding span with one number:" << std::endl;
    try
    {
        Span sp_small = Span(1);
        sp_small.addNumber(100);
        sp_small.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught expected error: " << e.what() << '\n';
    }
    
    std::cout << "\n--- Large Number Test with addNumbers() ---" << std::endl;
    try
    {
        Span sp_large = Span(15000);
        std::vector<int> numbers_to_add;
        for (int i = 0; i < 15000; ++i)
        {
            numbers_to_add.push_back(i * 3);
        }
        
        sp_large.addNumbers(numbers_to_add.begin(), numbers_to_add.end());

        std::cout << "Large Span Shortest span: " << sp_large.shortestSpan() << std::endl;
        std::cout << "Large Span Longest span:  " << sp_large.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    std::cout << "\n--- Copy and Assignment Test ---" << std::endl;
    try {
        Span s1(3);
        s1.addNumber(1);
        s1.addNumber(50);
        s1.addNumber(100);

        Span s2 = s1;
        Span s3(1);
        s3 = s1;

        std::cout << "Original longest span: " << s1.longestSpan() << std::endl;
        std::cout << "Copy's longest span:   " << s2.longestSpan() << std::endl;
        std::cout << "Assigned longest span: " << s3.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in copy test: " << e.what() << '\n';
    }

    return 0;
}