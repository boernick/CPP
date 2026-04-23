/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:33:54 by nick              #+#    #+#             */
/*   Updated: 2026/04/23 11:45:41 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &o) : _vec(o._vec), _deq(o._deq) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &o)
{
    if (this != &o) { _vec = o._vec; _deq = o._deq; }
    return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream ss(argv[i]);
        long val;
        char leftover;
        if (!(ss >> val) || ss.get(leftover))
            throw std::invalid_argument(std::string("Invalid token: ") + argv[i]);
        if (val <= 0)
            throw std::invalid_argument("Only positive integers are allowed.");
        if (val > 2147483647)
            throw std::invalid_argument("Integer overflow.");

        // Check duplicates
        for (size_t j = 0; j < _vec.size(); ++j)
            if (_vec[j] == (int)val)
                throw std::invalid_argument("Duplicate values are not allowed.");

        _vec.push_back((int)val);
        _deq.push_back((int)val);
    }
    if (_vec.empty())
        throw std::invalid_argument("No input provided.");
}

void PmergeMe::displaySequence(const std::string &label, const std::vector<int> &seq)
{
    std::cout << label;
    for (size_t i = 0; i < seq.size(); ++i)
        std::cout << seq[i] << (i + 1 < seq.size() ? " " : "");
    std::cout << "\n";
}


std::vector<int> PmergeMe::jacobsthalOrder(int n)
{
    // Build enough Jacobsthal numbers to cover n elements
    std::vector<int> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < n)
        jac.push_back(jac[jac.size()-1] + 2 * jac[jac.size()-2]);

    std::vector<int> order;
    std::vector<bool> inserted(n, false);

    for (size_t k = 2; k < jac.size(); ++k)
    {
        int hi = std::min(jac[k], n) - 1; // 0-based
        int lo = jac[k-1];                // 0-based (exclusive lower)

        // Insert from hi down to lo
        for (int idx = hi; idx >= lo && idx < n; --idx)
        {
            if (!inserted[idx])
            {
                order.push_back(idx);
                inserted[idx] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (!inserted[i])
            order.push_back(i);

    return order;
}

// VECTOR  –  Ford-Johnson / merge-insert sort

// Binary-search insert of val into sorted chain [0, bound)
void PmergeMe::insertVec(std::vector<int> &chain, int val)
{
    int lo = 0, hi = (int)chain.size();
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (chain[mid] < val) lo = mid + 1;
        else                  hi = mid;
    }
    chain.insert(chain.begin() + lo, val);
}

void PmergeMe::mergeInsertVec(std::vector<int> &seq)
{
    int n = (int)seq.size();
    if (n <= 1) return;

    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? seq.back() : 0;

    // Step 1: sort pairs so that larger is first
    for (int i = 0; i + 1 < n - (hasStraggler ? 1 : 0); i += 2)
        if (seq[i] < seq[i + 1])
            std::swap(seq[i], seq[i + 1]);

    // Step 2: collect "main chain" (larger of each pair) and "pend" (smaller)
    int pairCount = n / 2;
    std::vector<int> main_chain, pend;
    for (int i = 0; i < pairCount; ++i)
    {
        main_chain.push_back(seq[i * 2]);
        pend.push_back(seq[i * 2 + 1]);
    }

    // Step 3: recursively sort the main chain
    mergeInsertVec(main_chain);

    // Step 4: b[0] (pend[0]) pairs with a[0] (now the smallest in main chain)
    // b[0] <= a[0] by construction, so insert at front
    insertVec(main_chain, pend[0]);

    // Step 5: insert remaining pend elements using Jacobsthal order
    if ((int)pend.size() > 1)
    {
        std::vector<int> order = jacobsthalOrder((int)pend.size() - 1);
        for (size_t k = 0; k < order.size(); ++k)
        {
            int pendIdx = order[k] + 1; // +1 because pend[0] already inserted
            insertVec(main_chain, pend[pendIdx]);
        }
    }

    // Step 6: insert straggler if any
    if (hasStraggler)
        insertVec(main_chain, straggler);

    seq = main_chain;
}

// DEQUE  –  Ford-Johnson / merge-insert sort

void PmergeMe::insertDeq(std::deque<int> &chain, int val)
{
    int lo = 0, hi = (int)chain.size();
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (chain[mid] < val) lo = mid + 1;
        else                  hi = mid;
    }
    chain.insert(chain.begin() + lo, val);
}

void PmergeMe::mergeInsertDeq(std::deque<int> &seq)
{
    int n = (int)seq.size();
    if (n <= 1) return;

    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? seq.back() : 0;

    for (int i = 0; i + 1 < n - (hasStraggler ? 1 : 0); i += 2)
        if (seq[i] < seq[i + 1])
            std::swap(seq[i], seq[i + 1]);

    int pairCount = n / 2;
    std::deque<int> main_chain, pend;
    for (int i = 0; i < pairCount; ++i)
    {
        main_chain.push_back(seq[i * 2]);
        pend.push_back(seq[i * 2 + 1]);
    }

    mergeInsertDeq(main_chain);

    insertDeq(main_chain, pend[0]);

    if ((int)pend.size() > 1)
    {
        std::vector<int> order = jacobsthalOrder((int)pend.size() - 1);
        for (size_t k = 0; k < order.size(); ++k)
        {
            int pendIdx = order[k] + 1;
            insertDeq(main_chain, pend[pendIdx]);
        }
    }

    if (hasStraggler)
        insertDeq(main_chain, straggler);

    seq = main_chain;
}

void PmergeMe::sortAndDisplay()
{
    // Display "Before"
    std::vector<int> before(_vec.begin(), _vec.end());
    displaySequence("Before: ", before);

    // ── Vector sort ──
    std::clock_t startVec = std::clock();
    mergeInsertVec(_vec);
    std::clock_t endVec = std::clock();
    double timeVec = 1e6 * (double)(endVec - startVec) / CLOCKS_PER_SEC;

    // ── Deque sort ──
    std::clock_t startDeq = std::clock();
    mergeInsertDeq(_deq);
    std::clock_t endDeq = std::clock();
    double timeDeq = 1e6 * (double)(endDeq - startDeq) / CLOCKS_PER_SEC;

    // Display "After" (from vector)
    displaySequence("After:  ", _vec);

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us\n";
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << timeDeq << " us\n";
}
