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
#include <stdlib.h>
#include <iomanip>

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
        ScalarConverter();

    public:
        ScalarConverter( const std::string arg);
        ScalarConverter( ScalarConverter const & src);
        ~ScalarConverter(void);

        ScalarConverter & operator=(ScalarConverter const & rhs);
        
        static std::string  _str;
        static int          _type;

        static void convert(void);
        static int getType(void);
};

#endif