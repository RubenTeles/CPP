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

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char *file)
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

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src)
{
    *this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
    if (this != &rhs)
    {
        this->bitcoin.clear();

        for (std::map<int, std::map<std::string, std::string> >::const_iterator it = rhs.bitcoin.begin(); it != rhs.bitcoin.end(); ++it)
        {
            std::map<std::string, std::string> new_map;
            for (std::map<std::string, std::string>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            {
                new_map[it2->first] = it2->second;
            }
            this->bitcoin[it->first] = new_map;
        }
    }
    
    return *this;
}

float searchDataBase(std::string date, float bitcoin)
{
    std::ifstream	readFile;
	std::string		line;
    std::size_t     found;

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
                {
                    found = line.find(',');
                    if (found == std::string::npos)
                        throw std::invalid_argument("Erro: database is not okey!");
                    return (bitcoin * std::atof(line.substr(found+1, line.length()).c_str()));
                }
            }
            readFile.close();
        }
        if (date.length() < 1)
        {
            throw std::invalid_argument("Error: can find ");
            return 0;
        }
        
        char i = date[date.length() - 1];
        date = date.substr(0, date.length()-1).c_str();
        if (i > '0' && i <= '9')
        {
            i--;
            date.push_back(i);
        }
    }
}

void    BitcoinExchange::show(void)
{
    std::map<int, std::map<std::string, std::string> >::iterator it;
    
    std::cout << "Size: " << this->bitcoin.size() << std::endl;

    for (it = this->bitcoin.begin(); it != this->bitcoin.end(); ++it) 
    {
        if (it->first == 0)
            ++it;
        
        std::map<std::string, std::string> map = it->second;

        std::string data = it->second["data"];
        std::string value = it->second["value"];

        if (value == "" || data == "Error: bad input")
        {
            std::cout << data;
            if (data == "Error: bad input")
                std::cout << " => " << value;
            std::cout << std::endl;
        }
        else
        {
            std::cout << data << " => ";

            for (size_t i = 0; i < value.length(); i++)
            {
                if (value[i] >= '0' && value[i] <= '9')
                    std::cout << value[i];
            }
            float result = searchDataBase(data, std::atof(value.c_str()));
            if (result >= 1000000)
                std::cout << " = " << std::fixed << result << std::endl;
            else
                std::cout << " = " << result << std::endl;

        }
    }
}

std::string validDate(std::string date)
{
    std::size_t found;
    std::string dateAux;
    std::string aux;
    int         i = 0;
    double      dateNumber;
    double      year;
    double      month;
    double      day;

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
        dateNumber = std::atof(aux.c_str());
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
    for (unsigned long i = 0; i < value.length() - 1; i++)
    {
        if (!(value[i] >= '0' && value[i] <= '9') &&
            !(value[i] <= 31 && value[i] >= 0) &&
            value[i] != '.' && value[0] != '-')
            return "Error: bad input => ";
    }

    float	numb = std::atof(value.c_str());

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

    std::map<std::string, std::string> dados_bitcoin;
    dados_bitcoin.insert(std::make_pair("data", date));
    dados_bitcoin.insert(std::make_pair("value", value));

    this->bitcoin.insert(std::make_pair(this->bitcoin.size(), dados_bitcoin));
}