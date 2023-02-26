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

ScalarConverter::ScalarConverter(void)
{
    std::cout << "ScalarConverter default Constructor!" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter Destructor!" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    (void)rhs;


    return *this;
}

void    ScalarConverter::convert(std::string str, int type)
{
    if (type == TYPE_CHR)
    {
        if (isprint(str[0]))
            std::cout << "char: " << "\'" << this->c  << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(this->i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(this->i) << std::endl;
    }
    else if (type == TYPE_INT)
    {
        long long aux = atoi(str.c_str());

        if (aux > 2147483647 || aux < -2147483648)
        {
            std::cout << "This Valor is overflow!" << std::endl;
            return ;
        }
        int i = static_cast<int>(aux);
        if (isprint(i))
            std::cout << "char: " << "\'" << static_cast<char>(i) << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
    else if (type == TYPE_FLT)
    {
        if (str == "nanf" || str == "-inff" || str == "+inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << str << std::endl;
            std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
            return ;
        }
        //TODO
       /* int i = static_cast<int>(str);
        if (isprint(i))
            std::cout << "char: " << "\'" << this->c  << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;*/
    }
    else if (type == TYPE_DBL)
    {
        if (str == "nan" || str == "-inf" || str == "+inf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << str << "f" <<std::endl;
            std::cout << "double: " << str << std::endl;
            return ;
        }

	    double	d = strtod(str.c_str(), NULL);

        if (isprint(d))
            std::cout << "char: " << "\'" << static_cast<char>(d) << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: Impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
            std::cout << "float: Impossible" << std::endl;
        else
            std::cout << "float: " << d << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    
}