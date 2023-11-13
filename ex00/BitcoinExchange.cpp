/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:30:25 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/13 17:21:17 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& inst)
{    *this = inst;  }

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& inst)
{
    if (this != &inst)
    {
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void    BitcoinExchange::checkArg(int argsCounter) const
{
    if (argsCounter != 2)
        throw std::out_of_range("could not open file.");
}

void    BitcoinExchange::checkArgValue(char *av) const
{
    std::string arg = av;
    if (arg != "input.txt")
        throw std::out_of_range("could not open file.");
}

void    BitcoinExchange::checkData(const char *data) const
{
    std::ifstream   ifs;
    std::string     line;
    ifs.open(data, std::ifstream::in);
    std::getline(ifs, line);
    if (line != "date,exchange_rate")
        throw std::out_of_range("wrong file");
}

void    BitcoinExchange::checkInput(const char *input) const
{
    std::ifstream   ifs;
    std::string     line;
    ifs.open(input, std::ifstream::in);
    std::getline(ifs, line);
    if (line != "date | value")
        throw std::out_of_range("File must start with 'date | value'");
    while (std::getline(ifs, line))
    {
        checkDate(line);
    }
}

void    BitcoinExchange::checkDate(std::string& line) const
{
    std::cout << line << std::endl;
    time_t  rawtime;
    struct tm   *timeinfo;
    int year, month, day;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    int firstMinus = -1;
    int secondMinus = -1;
    int pipe;
    for (int i = 0; i < line.size(); i++)
    {
        if (firstMinus != -1 && line[i] == '-')
            secondMinus = i;
        if (line[i] == '-' && secondMinus == -1)
            firstMinus = i; 
    }
    std::stringstream yearString;
    
    
}
