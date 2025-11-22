#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& src)
{
    *this = src;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& rhs)
{
    if (this != &rhs)
    {
        this->_stack = rhs._stack;
    }
    return *this;
}

bool RPN::isOperator(const std::string& token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::performOp(const std::string& op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");
    int b = _stack.top(); _stack.pop();
    int a = _stack.top(); _stack.pop();

    if (op == "+") _stack.push(a + b);
    else if (op == "-") _stack.push(a - b);
    else if (op == "*") _stack.push(a * b);
    else if (op == "/")
    {
        if (b == 0) throw std::runtime_error("Error");
        _stack.push(a / b);
    }
}

void RPN::calculate(const std::string& expression)
{
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (isOperator(token))
        {
            performOp(token);
        } else
        {
            if (token.size() != 1 || token[0] < '0' || token[0] > '9')
                throw std::runtime_error("Error");
            
            _stack.push(std::atoi(token.c_str()));
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << _stack.top() << std::endl;
}