/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:18 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 23:36:24 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "Animal default Constructor!" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "Animal Constructor!" << std::endl;
}

AAnimal::AAnimal( AAnimal const & src)
{
    *this = src;
}

AAnimal::~AAnimal() {
    std::cout << "Animal Destructor!" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }

    return *this;
}
        
std::string AAnimal::getType(void) const
{
    return this->_type;
}
