#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>
# include <stdexcept>

class RPN
{
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        void calculate(const std::string& expression);
    private:
        std::stack<int> _stack;
        bool isOperator(const std::string& token);
        void performOp(const std::string& op);
};

#endif