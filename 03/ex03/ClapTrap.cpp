/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 17:53:40 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hitPoints(10), _energyPoints(10), _atackDamage(0)
{
    std::cout << "ClapTrap default summoned!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _atackDamage(0) 
{
    std::cout << "ClapTrap " << this->_name << " was summoned!" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src)
{
    *this = src;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->_name << " was killed!" << std::endl;
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
    this->_name = name;
    this->_hitPoints = hitPoints;
    this->_energyPoints = energyPoints;
    this->_atackDamage = atackDamage;
}
        
std::string ClapTrap::getName(void) const
{
    return this->_name;
}

int ClapTrap::getHitPoints(void) const
{
    return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
    return this->_energyPoints;
}

int ClapTrap::getAtackDamage(void) const
{
    return this->_atackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        return ;
    }
    
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " don't have Energy Points to Atack ClapTrap "
        << target << "." <<std::endl;
        return ;
    }
    
    std::cout << "ClapTrap " << this->_name << " attacks "
    << target << ", causing " << this->_atackDamage <<
    " points of damage!" << std::endl;

    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        return ;
    }

    this->_hitPoints -= amount;

    std::cout << "ClapTrap " << this->_name << " take Damage -"
    << amount << " have " << this->_hitPoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        return ;
    }
    
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " don't have Energy Points be Repaired!" << std::endl;
        return;
    }
    
    this->_hitPoints += amount;
    this->_energyPoints--;

    std::cout << "ClapTrap " << this->_name << " use Repaired +"
    << amount << " have " << this->_hitPoints << " hit points and " 
    << this->_energyPoints << " Energy Points." << std::endl;
}
