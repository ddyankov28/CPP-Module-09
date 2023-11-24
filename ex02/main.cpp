/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:48 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/24 15:55:18 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (!enoughArgs(ac))
        return 1;
    if (!argIsPositiveInteger(ac, av))
        return 1;
    //printBefore(ac, av);

    //clock_t  startVector, endVector;
    //startVector = clock();
    std::vector<int>    vector;
    for (int i = 1; i < ac; i++)
        vector.push_back(atoi(av[i]));
    std::vector<std::pair<int, int> > pairs = groupElements(vector);
    std::vector<std::pair<int, int> > newPairs = swapPairs(pairs);
    
    std::vector<std::pair<int, int> >::iterator itBeg = newPairs.begin();
    while (itBeg != newPairs.end())
    {
        std::cout << "FIRST:    " << itBeg->first << std::endl;
        std::cout << "SECOND:    " << itBeg->second << std::endl;
        itBeg++;
    }


    std::vector<int>    largerNumbers = largersInPair(newPairs);
    sortVector(largerNumbers);
    printAfter(largerNumbers);
    int front = getFrontInt(newPairs, largerNumbers[0]);
    std::vector<int>::iterator begin = largerNumbers.begin();
    largerNumbers.insert(begin, front);
    std::vector<std::pair<int, int> >::iterator itBegin = newPairs.begin();
    while (itBegin != newPairs.end())
    {
        std::cout << "SECOND FROM PAIR  " <<  itBegin->second << std::endl;
        std::cout << "FIRST FROM PAIR   " << itBegin->first << std::endl;
        std::vector<int>::iterator where = binarySearch(largerNumbers, itBegin->second);
        largerNumbers.insert(where, itBegin->second);
        itBegin++;
    }
    std::cout << "Large ";
    printAfter(largerNumbers);
    //endVector = clock();
    //double timeVector = double (endVector - startVector) / CLOCKS_PER_SEC;
    //printAfter(vector);
    //std::cout << "Time to process a range of " << ac -1 << " elements with std::vector:  " << std::fixed << timeVector << std::setprecision(6) << " us"<< std::endl;
    /*startDeque = clock();
    std::deque<int>  deque;
    for (int i = 1; i < ac; i++)
        deque.push_back(atoi(av[i]));
    sortDeque(deque);
    endDeque = clock();
    double timeDeque = double (endDeque - startDeque) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << ac -1 << " elements with std::deque:   " << std::fixed << timeDeque << std::setprecision(6) << " us"<< std::endl;*/
    return 0;
}
