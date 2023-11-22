/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:25 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/22 14:08:59 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

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
        //std::cout << "Left: " << vector[i] << std::endl;
        i++;
        left++;
    }
    while (right < rightVector.size())
    {
        vector[i] = rightVector[right];
        //std::cout << "Right: " << vector[i] << std::endl;
        i++;
        right++;
    }
}

void    sortDeque(std::deque<int>& deque)
{
    if (deque.size() < 2) 
        return ;
    std::deque<int>    leftDeque;
    std::deque<int>    rightDeque;
    unsigned int middle = deque.size() / 2;
    for (u_int i = 0; i < deque.size(); i++)
    {
        if (i < middle)
            leftDeque.push_back(deque[i]);
        else
            rightDeque.push_back(deque[i]); 
    }
    sortDeque(leftDeque);
    sortDeque(rightDeque);
    mergeDeque(leftDeque, rightDeque, deque);
}

void    mergeDeque(std::deque<int>& leftDeque, std::deque<int>& rightDeque, std::deque<int>& deque)
{
    u_int   i = 0, left = 0, right = 0;
    while (left < leftDeque.size() && right < rightDeque.size())
    {
        if (leftDeque[left] < rightDeque[right])
        {
           deque[i] = leftDeque[left];
           i++;
           left++;
        }
        else
        {
            deque[i] = rightDeque[right];
            i++;
            right++;
        }
    }
    while (left < leftDeque.size())
    {
        deque[i] = leftDeque[left];
        i++;
        left++;
    }
    while (right < rightDeque.size())
    {
        deque[i] = rightDeque[right];
        i++;
        right++;
    }
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
