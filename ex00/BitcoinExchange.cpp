/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:30:25 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/14 17:14:12 by ddyankov         ###   ########.fr       */
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

void    BitcoinExchange::getData(const char *data)
{
    std::ifstream   ifs;
    std::string     line;
    ifs.open(data, std::ifstream::in);
    std::getline(ifs, line);
    while (std::getline(ifs, line))
    {
        std::string date = line.substr(0, line.find(","));
        std::string exchangeVal = line.substr(line.find(",") + 1);
        //std::cout << date << " " << exchangeVal << std::endl;
        float mapValue;
        std::stringstream   ss(exchangeVal);
        ss >> mapValue;
        //std::cout << mapValue << std::endl;
        _map.insert(std::pair<std::string, float>(date, mapValue));
        
    }
    /*std::map<std::string,float>::iterator it = _map.begin();
    std::cout << "mymap contains:\n";
    for (it=_map.begin(); it !=_map.end(); it++)
        std::cout << it->first << " => " << it->second << '\n';*/
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
        if (!checkPipe(line)) 
             std::cout << "Bad Input => " << line << std::endl;
        if (checkInputDate(line) == 1)
             std::cout << "Bad Input => " << line << std::endl;
        else if (checkInputDate(line) == 2)
            std::cout << "Error: not a positive number." << std::endl;
        else if (checkInputDate(line) == 3)
            std::cout << "Error: too large a number." << std::endl;
        else
            std::cout << line << std::endl;
    }
}

bool    BitcoinExchange::checkPipe(std::string& line) const
{
    int pipe = -1;
    for (unsigned int i = 0; i < line.size(); i++)
    {
        if (line[i] == '|')
            pipe++;
    }
    if (!pipe)
        return true;
    return false;
}

int   BitcoinExchange::checkInputDate(std::string& line) const
{
    std::string date = line.substr(0, line.find("|") - 1);
    std::stringstream streamValue(line.substr(line.find("|") + 2));
    int dot = 0;
    for (unsigned int i = 0; i < streamValue.str().size(); i++)
    {
        if (!isdigit(streamValue.str()[i]) && streamValue.str()[i] != '.')
            return 1;
        if (streamValue.str()[i] == '.')
            dot++;
        if (dot > 1)
            return 1;
    }
    std::stringstream streamYear(date.substr(0, date.find("-")) );
    int year;
    float value;
    streamYear >> year;
    streamValue >> value;
    //std::cout << year << std::endl;
    //std::cout << value << std::endl;
    if (year <= 2009 || year >= 2030)
        return 1;
    if (value <= 0 )
        return 2;
    else if(value > 1000)
        return 3;
    return 0;
}