#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        _vectorData = src._vectorData;
        _dequeData = src._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No sequence provided." << std::endl;
        exit(1);
    }
    _parseInput(argc, argv);
}

bool PmergeMe::_isPositiveNumber(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!isdigit(str[i]))
            return false;
    }
    long val = std::atol(str.c_str());
    if (val < 0 || val > INT_MAX)
        return false;
    return true;
}

void PmergeMe::_parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (!_isPositiveNumber(arg))
        {
            std::cerr << "Error: Invalid number: " << arg << std::endl;
            exit(1);
        }
        int value = std::atoi(arg.c_str());
        _vectorData.push_back(value);
        _dequeData.push_back(value);
    }
}

void PmergeMe::execute()
{
    std::cout << "Before: ";
    size_t limit = _vectorData.size();
    if (limit > 5)
        limit = 5;
    for (size_t i = 0; i < limit; ++i)
        std::cout << _vectorData[i] << " ";
    if (_vectorData.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;

    clock_t startVec = clock();
    _sortVector(_vectorData);
    clock_t endVec = clock();
    double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    clock_t startDeq = clock();
    _sortDeque(_dequeData);
    clock_t endDeq = clock();
    double timeDeq = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
    std::cout << "After:  ";
    for (size_t i = 0; i < limit; ++i)
        std::cout << _vectorData[i] << " ";
    if (_vectorData.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}

void PmergeMe::_sortVector(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return;
    std::vector<int> larger;
    std::vector<int> smaller;
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (arr.size() % 2 != 0);
    if (hasStraggler) 
        straggler = arr.back();
    size_t end = arr.size();
    if (hasStraggler)
        end = arr.size() - 1;
    for (size_t i = 0; i < end; i += 2)
    {
        int n1 = arr[i];
        int n2 = arr[i+1];
        if (n1 > n2) 
            pairs.push_back(std::make_pair(n1, n2));
        else         
            pairs.push_back(std::make_pair(n2, n1));
    }
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        larger.push_back(pairs[i].first);
    }
    _sortVector(larger);
    std::vector<int> mainChain = larger;
    std::vector<int> pending;
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        int target = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == target)
            {
                pending.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    if (hasStraggler)
        pending.push_back(straggler);
    mainChain.insert(mainChain.begin(), pending[0]);
    _insertInVector(mainChain, pending);
    arr = mainChain;
}

void PmergeMe::_insertInVector(std::vector<int> &mainChain, std::vector<int> &pending)
{
    size_t jacobSeq[] =
    {
        1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923
    };
    size_t n = 0;
    size_t pendingIndex = 1;
    while (pendingIndex < pending.size())
    {
        size_t nextLimit = jacobSeq[n + 1]; 
        if (nextLimit >= pending.size())
            nextLimit = pending.size() - 1;

        for (size_t i = nextLimit; i >= pendingIndex; --i)
        {
            int value = pending[i];
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
            mainChain.insert(pos, value);
        }
        pendingIndex = nextLimit + 1;
        n++;
    }
}

void PmergeMe::_sortDeque(std::deque<int> &arr)
{
    if (arr.size() <= 1)
        return;
    std::deque<int> larger;
    std::deque<int> smaller;
    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (arr.size() % 2 != 0);
    if (hasStraggler)
        straggler = arr.back();
    size_t end = arr.size();
    if (hasStraggler)
        end = arr.size() - 1;
    for (size_t i = 0; i < end; i += 2)
    {
        int n1 = arr[i];
        int n2 = arr[i+1];
        if (n1 > n2)
            pairs.push_back(std::make_pair(n1, n2));
        else
            pairs.push_back(std::make_pair(n2, n1));
    }
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        larger.push_back(pairs[i].first);
    }
    _sortDeque(larger);
    std::deque<int> mainChain = larger;
    std::deque<int> pending;
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        int target = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == target)
            {
                pending.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    if (hasStraggler) 
        pending.push_back(straggler);
    mainChain.push_front(pending[0]);
    _insertInDeque(mainChain, pending);
    arr = mainChain;
}

void PmergeMe::_insertInDeque(std::deque<int> &mainChain, std::deque<int> &pending)
{
    size_t jacobSeq[] =
    {
        1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923
    };
    size_t n = 0;
    size_t pendingIndex = 1;

    while (pendingIndex < pending.size())
    {
        size_t nextLimit = jacobSeq[n + 1]; 
        if (nextLimit >= pending.size())
            nextLimit = pending.size() - 1;

        for (size_t i = nextLimit; i >= pendingIndex; --i)
        {
            int value = pending[i];
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
            mainChain.insert(pos, value);
        }
        pendingIndex = nextLimit + 1;
        n++;
    }
}