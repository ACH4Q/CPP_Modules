#ifndef RPN_HPP
#define RPN_HPP


# include <iostream>
# include <string>
# include <map>
# include <stack>
# include <deque>
# include <cstdlib>
# include <stdexcept>

template <typename Container = std::deque<int>>
class RPN
{
private:
    std::stack<int,Container>
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    void operations();
};



#endif