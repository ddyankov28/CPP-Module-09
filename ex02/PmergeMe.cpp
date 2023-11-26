/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:25 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/26 15:58:50 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

void    groupElementsVector(PmergeMe* merge)
{
    for (size_t i = 0; i < merge->startVector.size() - 1; i += 2)
        merge->pairsVector.push_back(std::pair<int, int>(merge->startVector[i], merge->startVector[i + 1]));
    if (merge->startVector.size() % 2 != 0)
        merge->pairsVector.push_back(std::make_pair(merge->startVector[merge->startVector.size() - 1], -1));
}

void    groupElementsDeque(PmergeMe* merge)
{
    for (size_t i = 0; i < merge->startDeque.size() - 1; i += 2)
        merge->pairsDeque.push_back(std::pair<int, int>(merge->startDeque[i], merge->startDeque[i + 1]));
    if (merge->startDeque.size() % 2 != 0)
        merge->pairsDeque.push_back(std::make_pair(merge->startDeque[merge->startDeque.size() - 1], -1));
}

void   swapPairsVector(PmergeMe* merge)
{
    std::vector<std::pair<int, int> >::iterator it = merge->pairsVector.begin();
    while (it != merge->pairsVector.end())
    {
        if (it->second > it->first)
            std::swap(it->first, it->second);
        it++;
    }
}

void   swapPairsDeque(PmergeMe* merge)
{
    std::deque<std::pair<int, int> >::iterator it = merge->pairsDeque.begin();
    while (it != merge->pairsDeque.end())
    {
        if (it->second > it->first)
            std::swap(it->first, it->second);
        it++;
    }
}

void    sortVector(std::vector<std::pair<int, int> >& pairs)
{
    if (pairs.size() < 2) 
        return ;
    std::vector<std::pair<int, int> >    leftPair;
    std::vector<std::pair<int, int> >    rightPair;
    unsigned int middle = pairs.size() / 2;
    for (u_int i = 0; i < pairs.size(); i++)
    {
        if (i < middle)
            leftPair.push_back(pairs[i]);
        else
            rightPair.push_back(pairs[i]); 
    }
    sortVector(leftPair);
    sortVector(rightPair);
    mergeVector(leftPair, rightPair, pairs);
}

void    sortDeque(std::deque<std::pair<int, int> >& pairs)
{
    if (pairs.size() < 2) 
        return ;
    std::deque<std::pair<int, int> >    leftPair;
    std::deque<std::pair<int, int> >    rightPair;
    unsigned int middle = pairs.size() / 2;
    for (u_int i = 0; i < pairs.size(); i++)
    {
        if (i < middle)
            leftPair.push_back(pairs[i]);
        else
            rightPair.push_back(pairs[i]); 
    }
    sortDeque(leftPair);
    sortDeque(rightPair);
    mergeDeque(leftPair, rightPair, pairs);
}

void    mergeVector(std::vector<std::pair<int, int> >&    leftPair, std::vector<std::pair<int, int> >&    rightPair, std::vector<std::pair<int, int> >& vector)
{
    u_int   i = 0, left = 0, right = 0;
    while (left < leftPair.size() && right < rightPair.size())
    {
        if (leftPair[left].first < rightPair[right].first)
        {
           vector[i] = leftPair[left];
           i++;
           left++;
        }
        else
        {
            vector[i] = rightPair[right];
            i++;
            right++;
        }
    }
    while (left < leftPair.size())
    {
        vector[i] = leftPair[left];
        i++;
        left++;
    }
    while (right < rightPair.size())
    {
        vector[i] = rightPair[right];
        i++;
        right++;
    }
}

void    mergeDeque(std::deque<std::pair<int, int> >&    leftPair, std::deque<std::pair<int, int> >&    rightPair, std::deque<std::pair<int, int> >& deque)
{
    u_int   i = 0, left = 0, right = 0;
    while (left < leftPair.size() && right < rightPair.size())
    {
        if (leftPair[left].first < rightPair[right].first)
        {
           deque[i] = leftPair[left];
           i++;
           left++;
        }
        else
        {
            deque[i] = rightPair[right];
            i++;
            right++;
        }
    }
    while (left < leftPair.size())
    {
        deque[i] = leftPair[left];
        i++;
        left++;
    }
    while (right < rightPair.size())
    {
        deque[i] = rightPair[right];
        i++;
        right++;
    }
}

void    insertInResultTheBiggerAndFirstSmallVector(PmergeMe* merge)
{
    std::vector<std::pair<int, int> >::const_iterator    itPairs = merge->pairsVector.begin();
    while (itPairs != merge->pairsVector.end())
    {
        merge->resultVector.push_back(itPairs->first);
        itPairs++;
    }
    itPairs = merge->pairsVector.begin();
    if (itPairs->second >= 0)
        merge->resultVector.insert(merge->resultVector.begin(), itPairs->second);
}

void    insertInResultTheBiggerAndFirstSmallDeque(PmergeMe* merge)
{
    std::deque<std::pair<int, int> >::const_iterator    itPairs = merge->pairsDeque.begin();
    while (itPairs != merge->pairsDeque.end())
    {
        merge->resultDeque.push_back(itPairs->first);
        itPairs++;
    }
    itPairs = merge->pairsDeque.begin();
    if (itPairs->second >= 0)
        merge->resultDeque.insert(merge->resultDeque.begin(), itPairs->second);
}

void    insertSmallerNumbersWithBinarySearchVector(PmergeMe* merge)
{
    std::vector<std::pair<int, int> >::const_iterator    itPairs = merge->pairsVector.begin() + 1;
    while (itPairs!= merge->pairsVector.end())
    {
        if (itPairs->second >= 0)
            merge->resultVector.insert(binarySearchVector(merge->resultVector, itPairs->second), itPairs->second);
        itPairs++;
    }
}

void    insertSmallerNumbersWithBinarySearchDeque(PmergeMe* merge)
{
    std::deque<std::pair<int, int> >::const_iterator    itPairs = merge->pairsDeque.begin() + 1;
    while (itPairs!= merge->pairsDeque.end())
    {
        if (itPairs->second >= 0)
            merge->resultDeque.insert(binarySearchDeque(merge->resultDeque, itPairs->second), itPairs->second);
        itPairs++;
    }
}

std::vector<int>::iterator  binarySearchVector(std::vector<int>& result, int target)
{
    std::vector<int>::iterator  start = result.begin();
    std::vector<int>::iterator  end = result.end();

    while (start < end)
    {
        std::vector<int>::iterator middle = start + (end - start) / 2;
        if (target > *middle)
            start = middle + 1;            
        else
            end = middle;
        //c++;
    }
    //std::cout << c << std::endl;

    return start;
}

std::deque<int>::iterator  binarySearchDeque(std::deque<int>& result, int target)
{
    std::deque<int>::iterator  start = result.begin();
    std::deque<int>::iterator  end = result.end();

    while (start < end)
    {
        std::deque<int>::iterator middle = start + (end - start) / 2;
        if (target > *middle)
            start = middle + 1;            
        else
            end = middle;
        //c++;
    }
    //std::cout << c << std::endl;

    return start;
}

bool    enoughArgs(int ac)
{
    if (ac < 3)
    {
        std::cerr << URED << "Error: Please enter more than 1 argument" << RESET << std::endl;
        return false;
    }
    return true;
}

bool    hasDuplicates(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        for (int j = i + 1; j < ac; ++j) 
        {
            if (atoi(av[i]) == atoi(av[j]))
            {
                std::cerr << URED << "Error: Duplicate number found and it is " << av[i] << RESET << std::endl;
                return true;
            }
        }
    }
    return false;

}
void    printPairs(std::vector<std::pair<int, int> >& vector)
{
    std::vector<std::pair<int, int > >::const_iterator    it = vector.begin();
    std::cout << "PAAIRS:    " << std::endl;
    while (it != vector.end())
    {
        std::cout << "First:    " << it->first << std::endl;
        std::cout << "Second:   " << it->second << std::endl;
        it++;
    }
}

void    printAfter(std::vector<int> vector)
{
    std::vector<int>::const_iterator    it = vector.begin();
    std::cout << "After:    ";
    while (it != vector.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}


bool    argIsPositiveInteger(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        int n = atoi(arg.c_str());
        std::stringstream   ss;
        ss << n;
        if (ss.str() != arg)
        {
            std::cerr << URED << "Error: Only positive integers allowed" << RESET << std::endl;
            return false;
        }
        for (unsigned int i = 0; i < arg.size(); i++)
        {
            if (!isdigit(arg[i]))
            {
                std::cerr << URED << "Error: Only positive integers allowed" << RESET << std::endl;
                return false;
            }
        }    
    }
    return true;
}

void    printBefore(int ac, char **av)
{
    std::cout << "Before:   ";
    for (int i = 1; i < ac; i++)
        std::cout << av[i] << " ";
    std::cout << std::endl;
}
