/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:57:22 by rteles            #+#    #+#             */
/*   Updated: 2023/03/13 22:22:15 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<int, std::map<std::string, std::string> > bitcoin;
        BitcoinExchange();
        void    divideInput(std::string input);

    public:
        BitcoinExchange(char *file);
        BitcoinExchange( BitcoinExchange const & src);
        ~BitcoinExchange();

        BitcoinExchange & operator=(BitcoinExchange const & rhs);

        void    show(void);
};

#endif