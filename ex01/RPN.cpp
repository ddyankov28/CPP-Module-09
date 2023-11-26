/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:08:52 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/26 16:58:42 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

bool    checkArgs(int ac)
{
    if (ac != 2)
    {
        std::cerr << URED << "Error: Wrong number of arguments" << RESET << std::endl;
        return true;
    }
    return false;
}

bool    checkLine(std::string& args)
{
    for (unsigned int i = 0; i < args.size(); i++)
    {
        if (!isspace(args[i]) && !isdigit(args[i]) && args[i] != '*' 
            && args[i] != '/' && args[i] != '+' && args[i] != '-')
        {
            std::cerr << URED << "Error: Invalid input" << RESET << std::endl;
            return true;
        } 
    }
    int i = static_cast<int>(args.size()) - 1;
    while(isspace(args[i]))
        i--;
    if (args[i] != '+' && args[i] != '-' && args[i] != '*' && args[i] != '/')
    {
        std::cerr << URED << "Error: Finish your expression with '+ , - , * or /'" << RESET << std::endl;
        return true;
    }
    for (unsigned int i = 0; i < args.size(); i++)
    {
        if (isdigit(args[i]) && isdigit(args[i + 1]))
        {
            std::cerr << URED << "Error: Number should be smaller than 10" << RESET << std::endl;
            return true;
        }
    }
    std::string::iterator it = args.begin();
    while (it != args.end())
    {
        if (isspace(*it))
            args.erase(it);
        else
            ++it;
    }
    if (isdigit(args[0]) && !isdigit(args[1]))
    {
        std::cerr << URED << "You need to insert two numbers at the beginning" << RESET << std::endl;
        return true;
    }
    if (checkDigitsAndOperators(args))
    {
        std::cerr << URED << "Error: Too much numbers between operators or too much operators" << RESET << std::endl;
        return true;
    }
    return false;
}

int calculate(std::string& args)
{
    int a = 0,b = 0;
    std::stack<int> stack; 
    std::string::iterator it = args.begin();
    while (it != args.end())
    {
        if (*it >= '0' && *it <= '9')
            stack.push(static_cast<int>(*it) - 48);
        else
        {
            b = stack.top();
            stack.pop();
            a = stack.top();
            stack.pop();
            stack.push(doOperation(a, b, it));
        }
        it++;
    }
    return (stack.top());
}

int doOperation(int a, int b, std::string::iterator it)
{
    if (*it == '+')
    {
        if (static_cast<long>(a) + static_cast<long>(b) > INT_MAX)
            throw std::out_of_range("Integer overflow");
        return a + b;
    }
    else if (*it == '-')
    {
        if (static_cast<long>(a) - static_cast<long>(b) < INT_MIN)
            throw std::out_of_range("Integer overflow");
        return a - b;
    }
    else if (*it == '/' && b == 0)
        throw std::out_of_range("Error: Can not divide by 0");
    else if (*it == '/')
        return a / b;
    else
    {
        if (static_cast<long>(a) * static_cast<long>(b) > INT_MAX)
            throw std::out_of_range("Integer overflow");
        return a * b;
    }
}

bool    checkDigitsAndOperators(std::string& args)
{
    int digitCount = 0, operatorCount = 0;

    for (unsigned int i = 0; i < args.size(); i++)
    {
        if (isdigit(args[i]))
            digitCount++;
        else
            operatorCount++;
    }
    if (digitCount - operatorCount != 1)
        return true;
    return false;
}
