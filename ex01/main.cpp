/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:08:34 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/20 16:56:51 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (checkArgs(ac))
            return 1;
        std::string args = av[1];
        if(checkLine(args))
            return 1;
        int result = calculate(args);
        std::cout << "Result is: " <<  result << std::endl;    
    }
    catch (std::exception& e)
    {
        std::cerr << URED << "Error: " << e.what() << RESET << std::endl;
    }
    return 0;
}