/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:48 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/21 17:28:37 by ddyankov         ###   ########.fr       */
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
    
    PmergeMe    sort;
    sort.insertVector(ac, av);
    sort.sortVector(sort.getVector());
    return 0;
}
