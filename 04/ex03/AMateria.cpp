/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:18 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 13:46:17 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->_type = type;
    std::cout << "AMateria Constructor!" << std::endl;
}

AMateria::AMateria( AMateria const & src)
{
    *this = src;
}

AMateria::~AMateria() {
    std::cout << "AMateria Destructor!" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }

    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}
