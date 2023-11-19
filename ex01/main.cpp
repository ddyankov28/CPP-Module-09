/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:08:34 by ddyankov          #+#    #+#             */
/*   Updated: 2023/11/19 17:53:47 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int main(int ac, char **av)
{
    if (checkArgs(ac))
        return 1;
    if(checkLine(av[1]))
        return 1;

    RPN rpn;


    return 0;
}