#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "--- MutantStack Test ---" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Stack contents:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);

    std::cout << "\n--- std::list Comparison Test ---" << std::endl;
    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << "Back: " << mlist.back() << std::endl;

    mlist.pop_back();

    std::cout << "Size: " << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator it_list = mlist.begin();
    std::list<int>::iterator ite_list = mlist.end();

    ++it_list;
    --it_list;

    std::cout << "List contents:" << std::endl;
    while (it_list != ite_list)
    {
        std::cout << *it_list << std::endl;
        ++it_list;
    }

    return 0;
}