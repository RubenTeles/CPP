/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:18:11 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_atackDamage = 20;
    
    std::cout << "ScavTrap default summoned!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->setAttributes(name, 100, 50, 20);
    std::cout << "ScavTrap " << this->getName() << " was summoned!" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src): ClapTrap(src)
{
    *this = src;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->getName() << " was killed!" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
    if (this != &rhs)
    {
        this->setAttributes(rhs.getName(), rhs.getHitPoints(), rhs.getEnergyPoints(), rhs.getAtackDamage());
    }

    return *this;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}