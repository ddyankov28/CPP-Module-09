/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:32:25 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/14 16:04:23 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BITCOIN_EXCHANGE
# define BITCOIN_EXCHANGE

# include <iostream>
# include <fstream>
# include <map>
# include <ctime>
# include <string>
# include <sstream>

# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;

class BitcoinExchange
{
    private:
        std::map<std::string, float>    _map;
    public:
        //  ...Orthodox Canonical Form... //
        BitcoinExchange();                                          // --- Constructor              --- //
        BitcoinExchange(const BitcoinExchange& inst);               // --- Copy Constructor         --- //
        BitcoinExchange&    operator=(const BitcoinExchange& inst); // --- Copy Assignment Operator --- //
        ~BitcoinExchange();                                         // --- Destructor               --- //

        void    checkArg(int argsCounter) const;
        void    checkArgValue(char *av) const;
        void    getData(const char *data);
        void    checkInput(const char *input) const;
        bool    checkPipe(std::string& line) const;
        int     checkInputDate(std::string& line) const;
};



# endif