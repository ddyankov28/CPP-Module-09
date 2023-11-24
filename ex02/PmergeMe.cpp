/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:25 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/24 15:47:15 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

std::vector<std::pair<int, int> >    groupElements(std::vector<int>& vec)
{
    std::vector<std::pair<int, int> >    pairs;

    for (size_t i = 0; i < vec.size() - 1; i += 2)
        pairs.push_back(std::pair<int, int>(vec[i], vec[i + 1]));
    if (vec.size() % 2 != 0)
        pairs.push_back(std::make_pair(vec[vec.size() - 1], -1));
    return pairs;
}

std::vector<int>    largersInPair(std::vector<std::pair<int, int> >& pairs)
{
    std::vector<std::pair<int, int> >::iterator it = pairs.begin();
    std::vector<int>    largeNumbers;
    while (it != pairs.end())
    {
        if (it->first > it->second)
            largeNumbers.push_back(it->first);
        else
            largeNumbers.push_back(it->second);
        std::cout << "First:  " << it->first << std::endl;
        std::cout << "Second: " << it->second << std::endl;
        it++;
    }
    return largeNumbers;
}

std::vector<std::pair<int, int> >   swapPairs(std::vector<std::pair<int, int> >& pairs)
{
    std::vector<std::pair<int, int> >::iterator it = pairs.begin();
    while (it != pairs.end())
    {
        if (it->second > it->first)
            std::swap(it->first, it->second);
        it++;
    }
    return pairs;
}

void    sortVector(std::vector<int>& vec)
{
    if (vec.size() < 2) 
        return ;
    std::vector<int>    leftVector;
    std::vector<int>    rightVector;
    unsigned int middle = vec.size() / 2;
    for (u_int i = 0; i < vec.size(); i++)
    {
        if (i < middle)
            leftVector.push_back(vec[i]);
        else
            rightVector.push_back(vec[i]); 
    }
    sortVector(leftVector);
    sortVector(rightVector);
    mergeVector(leftVector, rightVector, vec);
}

void    mergeVector(std::vector<int>& leftVector, std::vector<int>& rightVector, std::vector<int>& vector)
{
    u_int   i = 0, left = 0, right = 0;
    while (left < leftVector.size() && right < rightVector.size())
    {
        if (leftVector[left] < rightVector[right])
        {
           vector[i] = leftVector[left];
           i++;
           left++;
        }
        else
        {
            vector[i] = rightVector[right];
            i++;
            right++;
        }
    }
    while (left < leftVector.size())
    {
        vector[i] = leftVector[left];
        i++;
        left++;
    }
    while (right < rightVector.size())
    {
        vector[i] = rightVector[right];
        i++;
        right++;
    }
}

int     getFrontInt(std::vector<std::pair<int, int> >& pairs, int n)
{
    std::vector<std::pair<int, int> >::const_iterator itBegin = pairs.begin();

    while (itBegin != pairs.end())
    {
        if (itBegin->first == n)
            return itBegin->second;
        else if (itBegin->second == n)
            return itBegin->first;
        itBegin++;
    }
    return -1;
}

std::vector<int>::iterator  binarySearch(std::vector<int> largeNumbers, int target)
{
    std::vector<int>::iterator  start = largeNumbers.begin();
    std::vector<int>::iterator  end = largeNumbers.end();
    // std::cout << "START:    " << *start << std::endl;
    // std::cout << "END:    " << *end << std::endl;

    while (start < end)
    {
        std::vector<int>::iterator middle = start + (end - start) / 2;
        std::cout << "MIDDLE:   " << *middle << std::endl;
        std::cout << "TARGET:   " << target << std::endl;
        if (target > *middle)
            start = middle + 1;            
        else
            end = middle;
    }
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

void    printAfter(std::vector<int>& vector)
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
