/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/02/28 16:16:44 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"


int main(void)
{
    Data        data;
    Data        *data_ptr;
    uintptr_t   ptr;

    data.name = "Ruben";
    data.age = 26;

    std::cout << "Data:" << std::endl << " Name: " << data.name << std::endl << 
    " Age: " << data.age << std::endl << std::endl;

    Serializer ser;

    ptr = ser.serialize(&data);
    data_ptr = ser.deserialize(ptr);

    std::cout << "Data Pointer:" << std::endl << " Name: " << data_ptr->name << std::endl << 
    " Age: " << data_ptr->age << std::endl << std::endl;

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