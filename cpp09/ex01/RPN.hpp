#ifndef RPN_HPP
#define RPN_HPP


# include <iostream>
# include <string>
# include <map>
# include <stack>
# include <deque>
# include <cstdlib>
# include <stdexcept>

class RPN
{
private:
    std::stack<int,std::deque<int>> _mystack;
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    void operations();
};



#endif