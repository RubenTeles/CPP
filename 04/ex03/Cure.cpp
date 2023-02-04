/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 17:53:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
    std::cout << "Cure Constructor!" << std::endl;
}

Cure::Cure( Cure const & src): AMateria(src)
{    
    std::cout << "Cure Clonned!" << std::endl;

    *this = src;
}

Cure::~Cure() {
    std::cout << "Cure Destructor!" << std::endl;
}

Cure & Cure::operator=(Cure const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}