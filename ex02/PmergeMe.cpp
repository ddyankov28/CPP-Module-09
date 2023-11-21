/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:25 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/21 17:40:37 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& inst)
{   *this = inst;   }

PmergeMe&   PmergeMe::operator=(const PmergeMe& inst)
{
    if (this != &inst)
    {
        _vector = inst._vector;
        _list = inst._list;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void    PmergeMe::insertVector(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        _vector.push_back(atoi(av[i]));
}

void    PmergeMe::sortVector(std::vector<int>& vec)
{
    if (vec.size() < 2)
    {
        std::cout << "Vector has size 1" << std::endl;   
        return ;
    }
    std::vector<int>    leftVector;
    std::vector<int>    rightVector;
    unsigned int leftSize = vec.size() / 2;
    //std::cout << middle << std::endl;
    for (u_int i = 0; i < leftSize; i++)
    {
        leftVector.push_back(vec.at(i));
        std::cout << CYAN << "Vector [" << i << "]: " << vec.at(i) << " " << RESET << std::endl;
        std::cout << GREEN << "Left Vector [" << i << "]: " << leftVector.at(i) << " " << RESET << std::endl;
    }
    int i = 0;
    for (;leftSize < vec.size(); leftSize++)
    {
        rightVector.push_back(vec.at(leftSize));
        std::cout << CYAN << "Vector [" << leftSize << "]: " << vec.at(leftSize) << " " << RESET << std::endl;
        std::cout << RED << "Right Vector [" << i << "]: " << rightVector.at(i) << " " << RESET << std::endl;
        i++;
    }
    sortVector(leftVector);
    sortVector(rightVector);
}

std::vector<int>&   PmergeMe::getVector()
{
    return _vector;
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
