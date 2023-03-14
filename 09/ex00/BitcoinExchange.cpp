/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:57:22 by rteles            #+#    #+#             */
/*   Updated: 2023/03/13 20:10:12 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



BitcoinExchange::BitcoinExchange(std::string file)
{
    std::ifstream	readFile;
	std::string		line;

    readFile.open(file);
	
	if (readFile.fail())
	{
        throw std::invalid_argument("Error: could not open file.");
		return ;
	}
    if (readFile.is_open())
	{
		while (getline(readFile, line))
		{
            this->divideInput(line + "\n");
		}
		readFile.close();
	}

}

BitcoinExchange::~BitcoinExchange()
{
    
}

std::string validDate(std::string date)
{
    std::size_t found;
    std::string dateAux;
    int         i = 0;
    int         dateNumber;
    std::string aux;

    dateAux = date;
    found = dateAux.find("-");
    int startFound = 0;
    if (found == std::string::npos)
        return ("Error: bad input => " + date);
    while (i < 3)
    {
        i++;
        aux = date.substr(startFound, found);
        if ((i == 1 && aux.length() != 4) || ((i == 2 || i == 3) && aux.length() != 2))
            return ("Error: bad date => " + date);
        if (i == 2 || i == 3)
        {
            dateNumber = atoi(aux.c_str());
            if ((i == 2 && (dateNumber < 1 || dateNumber > 12)) || (i == 3 && (dateNumber < 1 || dateNumber > 31)))
            {
                std::cout << "Error: bad date =>: " << date << std::endl;
                return ("Error: bad date => " + date);
            }
        }
        dateAux = date.substr(startFound+found+1, date.length());
        startFound += found + 1;
        found = dateAux.find("-");
        //std::cout << "volta: " << i << " data: " << aux << " sstr: " << dateAux << " start: " << startFound <<" found: " << found << std::endl;
    }
    std::cout << std::endl;
    return date;
}

float validValue(std::string value)
{
    std::cout << "Valid Value: " << value << std::endl;
    for (int i = 0; i < value.length() - 1; i++)
    {
        if (!(value[i] >= '0' && value[i] <= '9') &&
            !(value[i] <= 31 && value[i] >= 0) &&
            value[i] != '.' && value[0] != '-')
            return -2;
    }
    
    float	numb = strtof(value.c_str(), NULL);

    if (numb > 1000 || numb < 0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 1001;
    }
    else if (numb < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return -1;
    }
    return numb;
}

void    BitcoinExchange::divideInput(std::string input)
{
    std::size_t found;
    std::string date;
    float         value;
    long        bitcoin;
	
	found = input.find(" | ");
  	if (found != std::string::npos)
  	{

		date = input.substr(0, found);
        date = validDate(date);
        value = validValue(input.substr(found + 3));
        /*if (date.length() > 10)
            value = -3;*/
        std::cout << "data: " << date << " value: " << value << std::endl;
        this->bitcoin.insert(std::pair<std::string, float>(date, 23));
  	}
    else
        std::cerr << "Error: bad input => " << input << std::endl;
}
