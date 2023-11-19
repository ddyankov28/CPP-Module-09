/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:08:52 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/19 17:56:12 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& inst)
{   *this = inst;   }

RPN&    RPN::operator=(const RPN& inst)
{
    (void)inst;
    return *this;
}

RPN::~RPN()
{}

bool    checkArgs(int ac)
{
    if (ac != 2)
    {
        std::cerr << URED << "Error: Wrong number of arguments" << RESET << std::endl;
        return true;
    }
    return false;
}

bool    checkLine(const char *av)
{
    std::string args = av;
    //std::cout << args << std::endl;

    for (unsigned int i = 0; i < args.size(); i++)
    {
        if (!isspace(args[i]) && !isdigit(args[i]) && args[i] != '*' 
            && args[i] != '/' && args[i] != '+' && args[i] != '-')
        {
            std::cerr << URED << "Error: Invalind input" << RESET << std::endl;
            return true;
        } 
    }
    int i = static_cast<int>(args.size()) - 1;
    while(isspace(args[i]))
        i--;
    //std::cout << args[i] << std::endl;
    if (args[i] != '+' && args[i] != '-' && args[i] != '*' && args[i] != '/')
    {
        std::cerr << URED << "Error: Finish your expression with '+ , - , * or /'" << RESET << std::endl;
        return true;
    }
    for (unsigned int i = 0; i < args.size(); i++)
    {
        if (isdigit(av[i]) && isdigit(av[i + 1]))
        {
            std::cerr << URED << "Error: Number should be smaller than 10" << RESET << std::endl;
            return true;
        }
    }
    return false;
}