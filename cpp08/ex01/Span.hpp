#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
    unsigned int N;
    std::vector<int> myVector;
public:
    Span();
    Span(unsigned int _N);
    Span(const Span& other);
    Span operator=(const Span& other);
    ~Span();
    void addNumber(int i);
    int shortestSpan();
    int longestSpan();

    class SpanIsNotCorrect : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
    
    template<typename T>
    void addnumbers(T begin, T end)
    {
        if (std::distance(begin,end) + myVector + 1 > N)
            throw SpanIsNotCorrect();
        myVector.insert(myVector.end(),begin, end);
    }    
};





#endif