/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:48 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/26 16:04:33 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (!enoughArgs(ac))
        return 1;
    if (!argIsPositiveInteger(ac, av))
        return 1;
    if (hasDuplicates(ac, av))
        return 1;
    printBefore(ac, av);
    PmergeMe    merge;
    
    // vector handling
    merge.startV = clock();
    for (int i = 1; i < ac; i++)
        merge.startVector.push_back(atoi(av[i]));
    groupElementsVector(&merge);
    swapPairsVector(&merge);
    sortVector(merge.pairsVector);
    insertInResultTheBiggerAndFirstSmallVector(&merge);
    insertSmallerNumbersWithBinarySearchVector(&merge);
    merge.endV = clock();
    merge.timeV = double(merge.endV - merge.startV) / CLOCKS_PER_SEC;

    // deque handling
    merge.startD = clock();
    for (int i = 1; i < ac; i++)
        merge.startDeque.push_back(atoi(av[i]));
    groupElementsDeque(&merge);
    swapPairsDeque(&merge);
    sortDeque(merge.pairsDeque);
    insertInResultTheBiggerAndFirstSmallDeque(&merge);
    insertSmallerNumbersWithBinarySearchDeque(&merge);
    merge.endD = clock();
    merge.timeD = double(merge.endD - merge.startD) / CLOCKS_PER_SEC;
    
    printAfter(merge.resultVector);

    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector:  "; 
    std::cout << std::fixed << merge.timeV << std::setprecision(6) << " us"<< std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque:   ";
    std::cout << std::fixed << merge.timeD << std::setprecision(6) << " us"<< std::endl;
    
    return 0;
}
