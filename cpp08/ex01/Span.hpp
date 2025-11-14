#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class Span
{
private:
    unsigned int N;
    std::vector<int> myVector;

public:
    Span();
    Span(unsigned int _N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();

    class SpanIsNotCorrect : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    template<typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end)
    {
        if (myVector.size() + static_cast<size_t>(std::distance(begin, end)) > N)
            throw SpanIsNotCorrect();
        
        myVector.insert(myVector.end(), begin, end);
    }
};

#endif