/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 17:53:40 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
}

Animal::Animal(std::string type) : _type(type)
{
}

Animal::Animal( Animal const & src)
{
    *this = src;
}

Animal::~Animal() {
}

Animal & Animal::operator=(Animal const & rhs)
{
    if (this != &rhs)
    {
        //Todo
       // this->setAttributes(rhs.getName(), rhs.getHitPoints(), rhs.getEnergyPoints(), rhs.getAtackDamage());
    }

    return *this;
}

/*void    Animal::setAttributes(std::string name, int hitPoints, int energyPoints, int atackDamage)
{
    this->_name = name;
    this->_hitPoints = hitPoints;
    this->_energyPoints = energyPoints;
    this->_atackDamage = atackDamage;
}*/
        
/*std::string Animal::getName(void) const
{
    return this->_name;
}*/

void Animal::makeSound(void) const
{
    std::cout << "animal sound" << std::endl;
}