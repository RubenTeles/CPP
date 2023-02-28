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

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter( ScalarConverter const & src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    (void)rhs;
    
    return *this;
}

void    ScalarConverter::convert(std::string str, int type)
{
    if (type == TYPE_CHR)
    {
        int    i;

        if (isprint(str[0]))
            std::cout << "char: " << "\'" << str[0]  << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        i = static_cast<int>(str[0]);
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << std::fixed << static_cast<double>(i) << std::endl;
    }
    else if (type == TYPE_INT)
    {
        long		aux = strtol(str.c_str(), NULL, 10);

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
    else if (type == TYPE_FLT)
    {
        if (str == "nanf" || str == "-inff" || str == "+inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << std::fixed << str << std::endl;
            std::cout << "double: " << std::fixed << str.substr(0, str.length() - 1) << std::endl;
            return ;
        }

	    float	flt = strtod(str.c_str(), NULL);

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
    else if (type == TYPE_DBL)
    {
        if (str == "nan" || str == "-inf" || str == "+inf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << std::fixed << str << "f" <<std::endl;
            std::cout << "double: " << std::fixed  << str << std::endl;
            return ;
        }

	    double	d = strtod(str.c_str(), NULL);

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
    
}