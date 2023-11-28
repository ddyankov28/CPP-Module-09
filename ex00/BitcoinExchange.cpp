/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:30:25 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/28 13:08:27 by ddyankov         ###   ########.fr       */
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
        _map = inst._map;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void    BitcoinExchange::checkArg(int argsCounter) const
{
    if (argsCounter != 2)
        throw std::out_of_range("could not open file.");
}

std::string    BitcoinExchange::getSeperator(const std::string& line) const
{
    std::string seperator = "a";
    for (u_int i = 0; i < line.size(); i++)
    {
        if (!isalnum(line[i]) && !isspace(line[i]))
        {
            seperator[0] = line[i];
            break ;
        }
    }
    if (seperator.size() != 1)
        throw std::out_of_range("Seperator should be a character");
    return seperator;
}

void    BitcoinExchange::getData(const char *data)
{
    std::ifstream   ifs(data);
    std::string     line;
    if (ifs.is_open())
    {
        std::getline(ifs, line);
        if (line.empty())
            throw std::out_of_range("Empty file");
        removeWhitespaces(line);
        std::string seperator = getSeperator(line);
        while (std::getline(ifs, line))
        {
            removeWhitespaces(line);
            if (line.empty())
                throw std::out_of_range("Error in data.csv or is empty");
            std::string date = line.substr(0, line.find(seperator));
            std::string exchangeVal = line.substr(line.find(seperator) + 1);
            float mapValue = 0;
            std::stringstream   ss(exchangeVal);
            ss >> mapValue;
            _map.insert(std::pair<std::string, float>(date, mapValue));
        }    
    }
    else
        throw std::out_of_range("could not open file"); 
    ifs.close();
    if (_map.empty())
        throw std::out_of_range("data.csv is empty");
}

void    BitcoinExchange::checkInput(const char *input) const
{
    std::ifstream   ifs(input);
    std::string     line;
    if (ifs.is_open())
    {
        std::getline(ifs, line);
        removeWhitespaces(line);
        if (line != "date|value")
            throw std::out_of_range("File must start with 'date | value' or file is empty");
        while (std::getline(ifs, line))
        {
            std::string lineOriginal = line;
            if(line.empty())
            {
                std::cerr << URED << "Error: empty line" << lineOriginal << RESET << std::endl;
                continue ;
            }
            removeWhitespaces(line);
            if (!checkPipe(line)) 
                std::cerr << URED << "Error: bad input => " << lineOriginal << RESET << std::endl;
            else if (checkInputLine(line, 0) == 2)
                std::cerr << URED << "Error: not a positive number." << RESET << std::endl;
            else if (checkInputLine(line, 0) == 3)
                std::cerr << URED << "Error: too large number." << RESET << std::endl;
            else if (checkInputLine(line, 1) == 1)
                std::cerr << URED << "Error: bad input => " << lineOriginal << RESET << std::endl;
        }    
    }
    else
        throw std::out_of_range("could not open file");
    ifs.close();
}

bool    BitcoinExchange::checkPipe(std::string& line) const
{
    if (line[line.size()- 1] == '|')
        return false;
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
        if (value[i] != '-' && !isdigit(value[i]) && value[i] != '.')
            return false;
    }
    return true;
}

int   BitcoinExchange::checkInputLine(std::string& line, int flag) const
{
    std::string date = line.substr(0, line.find("|"));
    if (date[4] != '-' || date[7] != '-' || date.size() > 10)
        return 1;
    std::stringstream streamValue(line.substr(line.find("|") + 1));
    if (!checkMinus(streamValue.str()))
        return 1;
    int dot = 0;
    for (unsigned int i = 0; i < streamValue.str().size(); i++)
    {
        if (!isdigit(streamValue.str()[i]) && streamValue.str()[i] != '.' && streamValue.str()[i] != '-')
            return 1;
        if (streamValue.str()[i] == '.')
            dot++;
        if (dot > 1 || (streamValue.str()[i] == '.' && i + 1 == streamValue.str().size()))
            return 1;
    }
    if (handleDate(date) == 1)
        return 1;
    float value;
    streamValue >> value;
    if (value < 0)
        return 2;
    else if (value > 1000)
        return 3;
    std::map<std::string, float>::const_iterator it = _map.lower_bound(date);
    if (_map.find(date) == _map.end())
        it--;
    float result = value * it->second;
    if (handleDate(date) == 2)
        result = value * 0;
    if (flag)
    {
        std::string newResult = formatDouble(result);
        std::cout << date << " => " << value << " = " << newResult << std::endl;
    }
    return 0;
}

int BitcoinExchange::handleDate(const std::string& date) const
{
    int year = atoi(date.substr(0, date.find("-")).c_str());
    int month = atoi(date.substr(5,2).c_str());
    int day = atoi(date.substr(8,2).c_str());
    
    if (year < 2009 || year >= 2030)
        return 1;
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return 1;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 1;
    if (year % 4 != 0 && month == 2 && day > 28)
        return 1;
    if (month == 2 && day > 29)
        return 1;
    if (year == 2009 && month == 1 && day == 1)
        return 2;
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

std::string BitcoinExchange::formatDouble(double result) const
{
    std::stringstream oss;
    oss << std::fixed << std::setprecision(3) << result;
    std::string formatted = oss.str();

    while (!formatted.empty() && (formatted[formatted.size() - 1] == '0' || formatted[formatted.size() - 1] == '.'))
        formatted.erase(formatted.size() - 1);
    if (formatted.empty())
        formatted = "0";
    return formatted;
}
