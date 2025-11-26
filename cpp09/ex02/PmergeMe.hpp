#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <climits>

class PmergeMe
{
    private:
        std::vector<int>    _vectorData;
        std::deque<int>     _dequeData;

        void    _parseInput(int argc, char **argv);
        bool    _isPositiveNumber(const std::string &str);

        void    _sortVector(std::vector<int> &arr);
        void    _insertInVector(std::vector<int> &mainChain, std::vector<int> &pendingChain);

        void    _sortDeque(std::deque<int> &arr);
        void    _insertInDeque(std::deque<int> &mainChain, std::deque<int> &pendingChain);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        PmergeMe(int argc, char **argv);

        void    execute();
};

#endif