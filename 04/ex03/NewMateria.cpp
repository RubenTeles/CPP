/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 17:53:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewMateria.hpp"

NewMateria::NewMateria(void): AMateria("NewMateria")
{
    std::cout << "NewMateria Constructor!" << std::endl;
}

NewMateria::NewMateria(std::string type): AMateria(type)
{
    std::cout << type << " NewMateria Constructor!" << std::endl;
}

NewMateria::NewMateria( NewMateria const & src): AMateria(src)
{    
    std::cout << "NewMateria Clonned!" << std::endl;

    *this = src;
}

NewMateria::~NewMateria() {
    std::cout << "NewMateria Destructor!" << std::endl;
}

NewMateria & NewMateria::operator=(NewMateria const & rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    
    return *this;
}

AMateria* NewMateria::clone() const
{
    return new NewMateria(this->getType());
}

void NewMateria::use(ICharacter& target)
{
    std::cout << "* use a " << this->getType() << " at " << target.getName() << std::endl;
}