/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:18 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 13:46:17 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal default Constructor!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal Constructor!" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src)
{
    *this = src;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor!" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }

    return *this;
}

std::string WrongAnimal::getType(void) const
{
    return this->_type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal sound" << std::endl;
}