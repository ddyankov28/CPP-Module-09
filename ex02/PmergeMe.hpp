/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:37 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/22 13:29:01 by ddyankov         ###   ########.fr       */
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

# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;


void    sortVector(std::vector<int>& vec);
void    mergeVector(std::vector<int>& leftVector, std::vector<int>& rightVector, std::vector<int>& vector);
void    sortDeque(std::deque<int>& deque);
void    mergeDeque(std::deque<int>& leftDeque, std::deque<int>& rightDeque, std::deque<int>& deque);
void    printAfter(std::vector<int>& vector);

bool    enoughArgs(int ac);
bool    argIsPositiveInteger(int ac, char **av);
void    printBefore(int ac, char **av);

# endif
