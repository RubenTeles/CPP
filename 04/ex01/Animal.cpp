/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:18 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 13:42:19 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal default Constructor!" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal Constructor!" << std::endl;

}

Animal::Animal( Animal const & src)
{
    *this = src;
}

Animal::~Animal() {
    std::cout << "Animal Destructor!" << std::endl;
}

Animal & Animal::operator=(Animal const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }

    return *this;
}
        
std::string Animal::getType(void) const
{
    return this->_type;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound" << std::endl;
}