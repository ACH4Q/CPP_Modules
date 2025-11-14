#include "Span.hpp"


Span::Span() : N(0) {}

Span::Span(unsigned int _N) : N(_N) {}

Span::Span(const Span& other)
{
    this->N = other.N;
}

Span Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int i)
{
    if (static_cast<int>(myVector.size()) >= static_cast<int>(i))
        throw SpanIsNotCorrect();
    myVector.push_back(i);
}

const char * Span::SpanIsNotCorrect::what() const throw()
{
    return "Span Error: Not enough numbers or capacity is full";
}

int Span::shortestSpan()
{
    if (myVector.size() < 2)
        throw SpanIsNotCorrect();
    std::vector<int> sortedVec = myVector;
    std::sort(myVector.begin(),myVector.end());
    int mini_span = 2147483647;
    for (size_t i = 0; i < sortedVec.size() - 1; ++i)
    {
        if (sortedVec[i + 1] - sortedVec[i] < mini_span)
            mini_span = sortedVec[i + 1] - sortedVec[i];
    }
    return mini_span; 
}

int Span::longestSpan()
{
    if (myVector.size() < 2)
        throw SpanIsNotCorrect();
    int min_value = *std::min_element(myVector.begin(),myVector.end());
    int max_value = *std::max_element(myVector.begin(),myVector.end());
    return (max_value - min_value);
}