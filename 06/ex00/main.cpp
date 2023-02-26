/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/02/26 02:12:07 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int getType(std::string str)
{
    bool        has_f = false;
    bool        has_doot = false;
    bool        is_negative = (str[0] == '-');
    int         len = str.length();
    std::size_t found = str.find(".");

    if (len == 0)
        return TYPE_UNK;
    if (len == 1)
    {
        if (!(str[0] >= 32 && str[0] <= 126))
            return TYPE_UNK;
        if (str[0] >= 48 && str[0] <= 57)
            return TYPE_INT;
        return TYPE_CHR;
    }
    if (str == "nanf" || str == "-inff" || str == "+inff")
        return TYPE_FLT;
    if (str == "nan" || str == "-inf" || str == "+inf")
        return TYPE_DBL;
    
    if (found != std::string::npos && static_cast<int>(found) != 0)
        has_doot = true;
    
    if (str[len - 1] == 'f' || str[len - 1] == 'F')
        has_f = true;

    for (int i = 0; i < len; i++)
    {
        if (i == 0 && is_negative)
            i++;

        if (has_doot && (int)found == i)
            i++;
            
        if (has_f && has_doot && i == len - 1)
            return TYPE_FLT;
            
        if (!isdigit(str[i]))
            return TYPE_UNK;
    }

    if (has_doot)
        return TYPE_DBL;
    
    return TYPE_INT;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;

    ScalarConverter type;

    switch (getType(argv[1]))
    {
        case TYPE_CHR:
            type.convert(argv[1], TYPE_CHR);
            break;
        case TYPE_INT:
            type.convert(argv[1], TYPE_INT);
            break;
        case TYPE_DBL:
            type.convert(argv[1], TYPE_DBL);
            break;
        case TYPE_FLT:
            type.convert(argv[1], TYPE_FLT);
            break;
        default:
            std::cout << "This Type don't make any sense!" << std::endl;
            break;
    }

    return 0;
}
/*
    //Durante a compilaçao 
    //static_cast< >();

    //Durante a execuçao
    //dynamic_cast< *>();

    //float > void * > int * / int &
    //reinterpret_cast< *>();

    //converte const para uma nao constante 
    //const_cast< *>()
*/