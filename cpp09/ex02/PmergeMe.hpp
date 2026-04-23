#pragma once

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void parseInput(int argc, char **argv);
    void sortAndDisplay();

private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    //  Vector sort 
    void        mergeInsertVec(std::vector<int> &seq);
    void        insertVec(std::vector<int> &chain, int val);

    //  Deque sort 
    void        mergeInsertDeq(std::deque<int> &seq);
    void        insertDeq(std::deque<int> &chain, int val);

    //  Jacobsthal 
    static std::vector<int> jacobsthalOrder(int n);

    //  Helpers 
    static void displaySequence(const std::string &label, const std::vector<int> &seq);
};