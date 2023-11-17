/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:30:25 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/17 13:02:13 by ddyankov         ###   ########.fr       */
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
    for (it=_map.begin(); it !=_map.end(); it++)
        std::cout << it->first << " => " << it->second << '\n';*/
}

void    BitcoinExchange::checkInput(const char *input) const
{
    std::ifstream   ifs;
    std::string     line;
    std::string     modifiedLine;
    ifs.open(input, std::ifstream::in);
    std::getline(ifs, line);
    removeWhitespaces(line);
    if (line != "date|value")
        throw std::out_of_range("File must start with 'date | value'");
    while (std::getline(ifs, line))
    {
        std::string lineOriginal = line;
        removeWhitespaces(line);
        if (!checkPipe(line)) 
             std::cout << "Bad Input => " << lineOriginal << std::endl;
        else if (checkInputDate(line, 0) == 2)
            std::cout << "Error: not a positive number." << std::endl;
        else if (checkInputDate(line, 0) == 3)
            std::cout << "Error: too large a number." << std::endl;
        else if (checkInputDate(line, 1) == 1)
             std::cout << "Bad Input => " << lineOriginal << std::endl;
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

bool    BitcoinExchange::checkMinus(const std::string& value) const
{
    int minus = 0;
    for (unsigned int i = 0; i < value.size(); i++)
    {
        if (value[i] == '-')
            minus++;
        if (minus > 1)
            return false;
    }
    return true;
}

int   BitcoinExchange::checkInputDate(std::string& line, int flag) const
{
    std::string date = line.substr(0, line.find("|"));
    //std::cout << "Date: " << date << std::endl;
    if (date[4] != '-' || date[7] != '-')
        return 1;
    std::stringstream streamValue(line.substr(line.find("|") + 1));
    if (!checkMinus(streamValue.str()))
        return 1;
    if (atoi(streamValue.str().c_str()) <= 0)
        return 2;
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
    std::stringstream   streamYear(date.substr(0, date.find("-")));
    int year;
    streamYear >> year;
    if (year <= 2009 || year >= 2030)
        return 1;
    float value;
    streamValue >> value;
    if (value <= 0 )
        return 2;
    else if(value > 1000)
        return 3;
    //std::cout << "Year: " << year << std::endl;
    //std::cout << "Value: " << value << "\n\n" << std::endl;
    std::stringstream   streamMonth(date.substr(5,2));
    int month;
    streamMonth >> month;
    //std::cout << "Month: " << month << std::endl;
    std::stringstream   streamDay(date.substr(8,2));
    int day;
    streamDay >> day;
    //std::cout << "Day: " << day << std::endl;
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return 1;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 1;
    if (year % 4 != 0 && month == 2 && day > 28)
        return 1;
    if (month == 2 && day > 29)
        return 1;
    std::map<std::string, float>::const_iterator it = _map.lower_bound(date);
    if (_map.find(date) == _map.end())
        it--;
    float result = value * it->second;
    if (flag)
        std::cout << date << " => " << value << " = " <<std::fixed << std::setprecision(1) << result << std::endl;
    return 0;
}

void    BitcoinExchange::removeWhitespaces(std::string& line) const
{
    std::string::iterator it = line.begin();
    while (it != line.end())
    {
        if (isspace(*it))
            line.erase(it);
        else
            ++it;
    }
}