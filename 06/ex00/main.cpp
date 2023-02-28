/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/02/28 18:40:10 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "You need write a parameter!" << std::endl;
        return 0;
    }

    ScalarConverter converter(argv[1]);

    converter.convert();

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