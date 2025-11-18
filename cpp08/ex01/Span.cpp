#include "Span.hpp"
#include <limits>

Span::Span() : N(0) {}

Span::Span(unsigned int _N) : N(_N) 
{
}

Span::Span(const Span& other)
{
    this->N = other.N;
    this->myVector = other.myVector;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->myVector = other.myVector;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (myVector.size() >= N)
        throw SpanIsNotCorrect();
    
    myVector.push_back(number);
}

const char* Span::SpanIsNotCorrect::what() const throw()
{
    return "Span Error: Not enough numbers to find a span or capacity is full.";
}

int Span::shortestSpan()
{
    if (myVector.size() < 2)
        throw SpanIsNotCorrect();

    std::vector<int> sortedVec = myVector;
    std::sort(sortedVec.begin(), sortedVec.end());

    long min_span = std::numeric_limits<long>::max();

    for (size_t i = 0; i < sortedVec.size() - 1; ++i)
    {
        long current_span = static_cast<long>(sortedVec[i + 1]) - static_cast<long>(sortedVec[i]);
        if (current_span < min_span)
            min_span = current_span;
    }
    return static_cast<int>(min_span);
}

int Span::longestSpan()
{
    if (myVector.size() < 2)
        throw SpanIsNotCorrect();

    int min_value = *std::min_element(myVector.begin(), myVector.end());
    int max_value = *std::max_element(myVector.begin(), myVector.end());
    
    return (max_value - min_value);
}