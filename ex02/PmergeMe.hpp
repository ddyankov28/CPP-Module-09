/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:37 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/26 16:02:12 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <sstream>
# include <vector>
# include <deque>
# include <ctime>
# include <iomanip>
# include <algorithm>

# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;

//static int c;

struct PmergeMe
{
    std::vector<int>                    startVector;
    std::vector<std::pair<int, int> >   pairsVector;
    std::vector<int>                    resultVector;
    clock_t                             startV;
    clock_t                             endV;
    double                              timeV;

    std::deque<int>                     startDeque;
    std::deque<std::pair<int, int> >    pairsDeque;
    std::deque<int>                     resultDeque;
    clock_t                             startD;
    clock_t                             endD;
    double                              timeD;
};
//      --- Input handling ---      //
bool    enoughArgs(int ac);
bool    argIsPositiveInteger(int ac, char **av);
bool    hasDuplicates(int ac, char **av);

void    printBefore(int ac, char **av);

//      --- Vector ---     ///
void    groupElementsVector(PmergeMe* merge);
void    swapPairsVector(PmergeMe* merge);
void    sortVector(std::vector<std::pair<int, int> >& pairs);
void    mergeVector(std::vector<std::pair<int, int> >& leftPair, std::vector<std::pair<int, int> >& rightPair, std::vector<std::pair<int, int> >& vector);
void    insertInResultTheBiggerAndFirstSmallVector(PmergeMe* merge);
void    insertSmallerNumbersWithBinarySearchVector(PmergeMe* merge);
std::vector<int>::iterator  binarySearchVector(std::vector<int>& result, int target);

//      --- Deque ---     ///
void    groupElementsDeque(PmergeMe* merge);
void    swapPairsDeque(PmergeMe* merge);
void    sortDeque(std::deque<std::pair<int, int> >& pairs);
void    mergeDeque(std::deque<std::pair<int, int> >& leftPair, std::deque<std::pair<int, int> >& rightPair, std::deque<std::pair<int, int> >& vector);
void    insertInResultTheBiggerAndFirstSmallDeque(PmergeMe* merge);
void    insertSmallerNumbersWithBinarySearchDeque(PmergeMe* merge);
std::deque<int>::iterator  binarySearchDeque(std::deque<int>& result, int target);


void    printAfter(std::vector<int> vector);

//      --- Additional for debug purpose ---    ///
void    printPairs(std::vector<std::pair<int, int> >& vector);


# endif
