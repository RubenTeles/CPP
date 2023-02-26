/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:49:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

#include <iostream>
#include <limits>

enum type_enum {
    TYPE_CHR,
    TYPE_INT,
    TYPE_FLT,
    TYPE_DBL,
	TYPE_UNK,
};

class ScalarConverter
{
    private:
        char    c;
        int     i;
        double  dbl;
        float   flt;

    public:
        ScalarConverter();
        ScalarConverter( ScalarConverter const & src);
        virtual ~ScalarConverter(void);

        ScalarConverter & operator=(ScalarConverter const & rhs);
        operator float();
        operator int();
        operator char();

        void convert(std::string str, int type);
        void convertToChar(std::string str);
        void convertToInt(std::string str);
        void convertToDouble(std::string str);
        void convertToFloat(std::string str);
};


#endif