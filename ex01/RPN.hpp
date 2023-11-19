/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:08:45 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/19 16:43:05 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_HPP
# define RPN_HPP

# include <iostream>

# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;

class   RPN
{
    private:
        
    public:
        //  ...Orthodox Canonical Form... //
        RPN();                                  // --- Constructor              --- //
        RPN(const RPN& inst);                   // --- Copy Constructor         --- //
        RPN&    operator=(const RPN& inst);     // --- Copy assignment operator --- //
        ~RPN();                                 // --- Destructor               --- //
};

bool    checkArgs(int ac);
bool    checkLine(const char *av);

# endif