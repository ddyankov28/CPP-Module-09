/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:48 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/22 13:34:35 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (!enoughArgs(ac))
        return 1;
    if (!argIsPositiveInteger(ac, av))
        return 1;
    printBefore(ac, av);

    clock_t  startVector, endVector, startDeque, endDeque;
    startVector = clock();
    std::vector<int>    vector;
    for (int i = 1; i < ac; i++)
        vector.push_back(atoi(av[i]));
    sortVector(vector);
    endVector = clock();
    double timeVector = double (endVector - startVector) / CLOCKS_PER_SEC;
    printAfter(vector);
    std::cout << "Time to process a range of " << ac -1 << " elements with std::vector:  " << std::fixed << timeVector << std::setprecision(6) << " us"<< std::endl;
    startDeque = clock();
    std::deque<int>  deque;
    for (int i = 1; i < ac; i++)
        deque.push_back(atoi(av[i]));
    sortDeque(deque);
    endDeque = clock();
    double timeDeque = double (endDeque - startDeque) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << ac -1 << " elements with std::deque:   " << std::fixed << timeDeque << std::setprecision(6) << " us"<< std::endl;
    return 0;
}
