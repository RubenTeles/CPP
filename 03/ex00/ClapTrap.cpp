/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/30 23:17:58 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :  name(""), hitPoints(10), energyPoints(10), atackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " was summoned! " << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), atackDamage(0) 
{
    std::cout << "ClapTrap " << this->name << " was summoned! " << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src)
{
    *this = src;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " was killed! " << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
    if (this != &rhs)
    {
        this->setAttributes(rhs.getName(), rhs.getHitPoints(), rhs.getEnergyPoints(), rhs.getAtackDamage());
    }

    return *this;
}

void    ClapTrap::setAttributes(std::string name, int hitPoints, int energyPoints, int atackDamage)
{
    this->name = name;
    this->hitPoints = hitPoints;
    this->energyPoints = energyPoints;
    this->atackDamage = atackDamage;
}
        
std::string ClapTrap::getName(void) const
{
    return this->name;
}

int ClapTrap::getHitPoints(void) const
{
    return this->hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
    return this->energyPoints;
}

int ClapTrap::getAtackDamage(void) const
{
    return this->atackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
        return ;
    }
    
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " don't have Energy Points to Atack ClapTrap "
        << target << "." <<std::endl;
        return ;
    }
    
    std::cout << "ClapTrap " << this->name << " attacks "
    << target << ", causing " << this->atackDamage <<
    " points of damage!" << std::endl;

    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
        return ;
    }

    this->hitPoints -= amount;

    std::cout << "ClapTrap " << this->name << " take Damage -"
    << amount << " have " << this->hitPoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
        return ;
    }
    
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " don't have Energy Points be Repaired!" << std::endl;
        return;
    }
    
    this->hitPoints += amount;
    this->energyPoints--;

    std::cout << "ClapTrap " << this->name << " use Repaired +"
    << amount << " have " << this->hitPoints << " hit points and " 
    << this->energyPoints << " Energy Points." << std::endl;
}
