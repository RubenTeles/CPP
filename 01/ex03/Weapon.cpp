/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:27:48 by rteles            #+#    #+#             */
/*   Updated: 2023/01/29 21:31:41 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon()
{
}


std::string Weapon::getType(void) const
{
    return this->type;
}

void    Weapon::setType(std::string newType)
{
    this->type = newType;

    return ;
}
