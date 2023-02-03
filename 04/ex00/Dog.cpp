/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 17:53:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
    std::cout << "Dog Constructor!" << std::endl;
}

Dog::Dog( Dog const & src): Animal(src)
{
    *this = src;
}

Dog::~Dog() {
    std::cout << "Dog Destructor!" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }

    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "Au au!" << std::endl;
}