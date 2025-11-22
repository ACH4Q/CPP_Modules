#include "RPN.hpp"


RPN::RPN() {}

RPN::RPN(const RPN& other) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other)
{
    if (&other != this)
    {
        this->_mystack = other._mystack;
    }
    return *this;
}
