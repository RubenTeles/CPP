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
            this->divideInput(line);
		}
		readFile.close();
	}

}

BitcoinExchange::~BitcoinExchange()
{
    
}

float searchDataBase(std::string date, float bitcoin)
{
    std::ifstream	readFile;
	std::string		line;
    std::size_t     found;
    std::string     atualDate;
    float           multipication;

    while (1)
    {
        readFile.open("data.csv");
	
	    if (readFile.fail())
	    {
            throw std::invalid_argument("Error: could not open file.");
	    }

        if (readFile.is_open())
        {
            while (getline(readFile, line))
            {
                found = line.find(date);
                if (found != std::string::npos)
                    return (bitcoin * strtof(line.substr(found+1, line.length()).c_str(), NULL));
            }
            readFile.close();
        }
        if (date.length() < 1)
        {
            throw std::invalid_argument("Error: can find ");
            return 0;
        }
        date = date.substr(0, date.length()-1).c_str();
    }
}

void    BitcoinExchange::show(void)
{
    std::map<std::string, std::string>::iterator it;
    std::size_t found;
    std::string date;
    std::string needle;
    int i = 1;
    std::stringstream ss;
    
    std::cout << this->bitcoin.size() << std::endl;

    for (it = this->bitcoin.begin(); it != this->bitcoin.end(); ++it) 
    {
        if (i == 1)
            ++it;
       /* needle = "";
        ss.str("");
        ss << i;
        needle = ss.str();
	    found = it->first.find(needle);*/
        /*std:: cout <<  " nedle:" << needle << std::endl;
        std::cout << "found " << found <<" " << std::endl;*/

		date = it->first.substr(2);
        if (date.find("Error") != std::string::npos)
            std::cout << it->first << std::endl;
       /* else
        {
            std::cout << it->first << " => " << it->second << std::endl;*/
            //std::cout << searchDataBase(it->first, strtof(it->second.c_str(), NULL)) << std::endl;
       // }
        i++;
    }
}

std::string validDate(std::string date)
{
    std::size_t found;
    std::string dateAux;
    int         i = 0;
    double      dateNumber;
    double      year;
    double      month;
    double      day;
    std::string aux;

    dateAux = date;
    found = dateAux.find("-");
    int startFound = 0;
    if (found == std::string::npos)
        return ("Error: bad input");
    while (i < 3)
    {
        i++;
        aux = date.substr(startFound, found);
        if ((i == 1 && aux.length() != 4) || ((i == 2 || i == 3) && aux.length() != 2))
            return ("Error: bad date!");
        dateNumber = strtof(aux.c_str(), NULL);
        if (i == 1)
        {
            year = dateNumber;
            if (dateNumber < 2009 || dateNumber > 2022)
               return ("Error: bad date!");
        }
        if (i == 2)
        {
            month = dateNumber;
            if (dateNumber < 1 || dateNumber > 12)
                return ("Error: bad date!");
        }
        if (i == 3)
        {
            day = dateNumber;
            if (dateNumber < 1 || dateNumber > 31)
                return ("Error: bad date!");
        }
        dateAux = date.substr(startFound+found+1, date.length());
        startFound += found + 1;
        found = dateAux.find("-");
    }
    if (year == 2009 && month == 1 && day == 1)
        return ("Error: bad date, bitcoin don't exist!");

    if (year == 2022 && (month > 3 || (month == 3 && day > 29)))
        return ("Error: bad date, you are in the future!");

    return date;
}

std::string validValue(std::string value)
{
    for (int i = 0; i < value.length() - 1; i++)
    {
        if (!(value[i] >= '0' && value[i] <= '9') &&
            !(value[i] <= 31 && value[i] >= 0) &&
            value[i] != '.' && value[0] != '-')
            return "Error: bad input => ";
    }

    float	numb = strtof(value.c_str(), NULL);

    if (numb > 1000)
        return "Error: too large a number.";
    else if (numb < 0)
        return "Error: not a positive number.";
    return value;
}

void    BitcoinExchange::divideInput(std::string input)
{
    std::size_t found;
    std::string date;
    std::string value;
	
	found = input.find(" | ");
  	if (found != std::string::npos)
  	{
		date = input.substr(0, found);
        date = validDate(date);
        value = validValue(input.substr(found + 3));
        
	    if (date.find("Error") != std::string::npos)
            value = "";
        else if (value.find("Error") != std::string::npos)
        {
            date = value;
            value = "";
            if (date.find("bad input") != std::string::npos)
                value = input;
        }
  	}
    else
    {
        date = "Error: bad input";
        value = input;
    }
    int size = this->bitcoin.size();
    std::stringstream ss;
    ss << size;
    std::string str = ss.str();

    this->bitcoin.insert(std::pair<std::string, std::string>(str+" "+date, value));
}

/*
data:
    Mouth - 0<  >12
    Day - 0<  >31

value: 
    1001 - Error: too large a number.
    -1 - Error: not a positive number.
    -2 - Error: bad input =>
*/
