/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 13:35:41 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): WrongAnimal("Character")
{
    std::cout << "Character Constructor!" << std::endl;
}

Character::Character( Character const & src): WrongAnimal(src)
{
    *this = src;
}

Character::~Character() {
    std::cout << "Character Destructor!" << std::endl;
}

Character & Character::operator=(Character const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }

    return *this;
}

void Character::makeSound(void) const
{
    std::cout << "Piu Piu!" << std::endl;
}