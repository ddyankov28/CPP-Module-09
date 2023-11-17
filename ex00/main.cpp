/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:30:06 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/17 14:38:39 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        BitcoinExchange btc;
        
        btc.checkArg(ac);
        btc.getData("data.csv");
        btc.checkInput(av[1]);
    }
    catch(std::exception& e)
    {
        std::cerr << URED << "Error: " << e.what() << RESET << std::endl;
    }
    return 0;
}
