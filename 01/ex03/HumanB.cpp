/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:27:48 by rteles            #+#    #+#             */
/*   Updated: 2023/01/20 16:30:08 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
}

void    HumanB::attack(void)
{
    std::cout << this->name << "attacks with their" << this->wp.getType() << std::endl;
    return ;
}

void    HumanB::setWeapon(Weapon weapon)
{
    this->wp = weapon;

    return;
}