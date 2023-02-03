/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 13:35:41 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Constructor!" << std::endl;
}

WrongCat::WrongCat( WrongCat const & src): WrongAnimal(src)
{
    *this = src;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor!" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }

    return *this;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Piu Piu!" << std::endl;
}