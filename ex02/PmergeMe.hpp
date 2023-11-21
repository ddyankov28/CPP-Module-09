/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:37 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/21 17:31:12 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <sstream>
# include <vector>
# include <list>
# include <ctime>
# include <iomanip>

# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;

class   PmergeMe
{
    private:
        std::vector<int>    _vector;
        std::list<int>      _list;
    public:
        PmergeMe();                         //  Default Cnstructor
        PmergeMe(const PmergeMe& inst);     //  Copy constructor
        PmergeMe&   operator=(const PmergeMe& inst); // Copy assignment operator
        ~PmergeMe();

        void    insertVector(int ac, char **av);
        void    sortVector(std::vector<int>& vec);

        std::vector<int>&   getVector();
        
};

bool    enoughArgs(int ac);
bool    argIsPositiveInteger(int ac, char **av);
void    printBefore(int ac, char **av);

# endif
