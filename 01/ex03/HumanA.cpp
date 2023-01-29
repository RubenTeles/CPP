/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:27:48 by rteles            #+#    #+#             */
/*   Updated: 2023/01/24 16:20:47 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wp) : name(name), wp(wp)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack(void)
{
    std::cout << this->name << "attacks with their" << this->wp.getType() << std::endl;
    return ;
}