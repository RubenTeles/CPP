/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:18 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 17:40:29 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_str;
int ScalarConverter::_type;

ScalarConverter::ScalarConverter(void) {
    this->_str = "";
    this->_type = getType();
}

ScalarConverter::ScalarConverter(const std::string arg) {
    this->_str = arg;
    this->_type = getType();
}

ScalarConverter::ScalarConverter( ScalarConverter const & src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    if (this != &rhs)
    {
        this->_str = rhs._str;
        this->_type = rhs._type;
    }
    
    return *this;
}

int ScalarConverter::getType(void)
{
    std::string str = _str;
    bool        has_f = false;
    bool        has_doot = false;
    bool        is_negative = (str[0] == '-');
    int         len = str.length();
    std::size_t found = str.find(".");

    if (len == 0)
        return (TYPE_UNK);
    if (len == 1)
    {
        if (!(str[0] >= 32 && str[0] <= 126))
            return (TYPE_UNK);
        if (str[0] >= 48 && str[0] <= 57)
            return (TYPE_INT);
        return (TYPE_CHR);
    }
    if (str == "nanf" || str == "-inff" || str == "+inff")
        return (TYPE_FLT);
    if (str == "nan" || str == "-inf" || str == "+inf")
        return (TYPE_DBL);
    
    if (found != std::string::npos && static_cast<int>(found) != 0)
        has_doot = true;
    
    if (str[len - 1] == 'f' || str[len - 1] == 'F')
        has_f = true;

    if (has_doot && has_f && static_cast<int>(found) == len - 2)
        return (TYPE_UNK);

    for (int i = 0; i < len; i++)
    {
        if (i == 0 && is_negative)
            i++;

        if (has_doot && (int)found == i)
            i++;
            
        if (has_f && i == len - 1)
            return (TYPE_FLT);
            
        if (!isdigit(str[i]))
            return (TYPE_UNK);
    }

    if (has_doot)
        return (TYPE_DBL);
    
    return (TYPE_INT);
}

void    ScalarConverter::convert(void)
{
    if (_type == TYPE_CHR)
    {
        int    i;

        if (isprint(_str[0]))
            std::cout << "char: " << "\'" << _str[0]  << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        i = static_cast<int>(_str[0]);
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << std::fixed << static_cast<double>(i) << std::endl;
    }
    else if (_type == TYPE_INT)
    {
        long		aux = strtol(_str.c_str(), NULL, 10);

        if (aux > std::numeric_limits<int>::max() || aux < std::numeric_limits<int>::min())
        {
            std::cout << "This Valor is overflow!" << std::endl;
            return ;
        }
        int i = static_cast<int>(aux);
        std::cout << aux << std::endl;
        if (i > 126 || i < 32)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "\'" << static_cast<char>(i) << "\'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << std::fixed << static_cast<double>(i) << std::endl;
    }
    else if (_type == TYPE_FLT)
    {
        if (_str == "nanf" || _str == "-inff" || _str == "+inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << std::fixed << _str << std::endl;
            std::cout << "double: " << std::fixed << _str.substr(0, _str.length() - 1) << std::endl;
            return ;
        }

	    float	flt = strtod(_str.c_str(), NULL);

        if (flt > 126 || flt < 32)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "\'" << static_cast<char>(flt) << "\'" << std::endl;
        if (flt > std::numeric_limits<int>::max() || flt < std::numeric_limits<int>::min())
            std::cout << "int: Impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(flt) << std::endl;

        std::cout << "float: " << std::fixed << flt << "f" << std::endl;
        if (flt > std::numeric_limits<double>::max() || flt < std::numeric_limits<double>::min())
            std::cout << "float: Impossible" << std::endl;
        else
            std::cout << "double: " << std::fixed << static_cast<double>(flt) << std::endl;
    }
    else if (_type == TYPE_DBL)
    {
        if (_str == "nan" || _str == "-inf" || _str == "+inf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << std::fixed << _str << "f" <<std::endl;
            std::cout << "double: " << std::fixed  << _str << std::endl;
            return ;
        }

	    double	d = strtod(_str.c_str(), NULL);

        if (d > 126 || d < 32)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "\'" << static_cast<char>(d) << "\'" << std::endl;
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: Impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
            std::cout << "float: Impossible" << std::endl;
        else
            std::cout << "float: " << std::fixed << d << "f" << std::endl;
        std::cout << "double: " << std::fixed << d << std::endl;
    }
    else
        std::cout << "This Type don't make any sense!" << std::endl;
}