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

}

int Span::shortestSpan()
{
    if (myVector.size() < 2)
        throw SpanIsNotCorrect();
    int min_value = 0;
    int max_value = 1;
    return ()
}

int Span::longestSpan()
{
    if (myVector.size() < 2)
        throw SpanIsNotCorrect();
    int min_value = *std::min_element(myVector.begin(),myVector.end());
    int max_value = *std::max_element(myVector.begin(),myVector.end());
    return (max_value - min_value);
}