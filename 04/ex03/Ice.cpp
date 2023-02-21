/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:59:36 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 12:41:09 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
    std::cout << "Ice Constructor!" << std::endl;
}

Ice::Ice( Ice const & src): AMateria(src)
{    
    std::cout << "Ice Clonned!" << std::endl;

    *this = src;
}

Ice::~Ice()
{
    std::cout << "Ice Destructor!" << std::endl;
}

Ice & Ice::operator=(Ice const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}