#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe <positive integers...>\n";
        return 1;
    }
    try
    {
        PmergeMe pm;
        pm.parseInput(argc, argv);
        pm.sortAndDisplay();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}