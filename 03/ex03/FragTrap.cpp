/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:18:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_atackDamage = 30;
    
    std::cout << "FragTrap default summoned!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->setAttributes(name, 100, 100, 30);
    std::cout << "FragTrap " << this->getName() << " was summoned!" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src): ClapTrap(src)
{
    *this = src;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->getName() << " was killed!" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
    if (this != &rhs)
    {
        this->setAttributes(rhs.getName(), rhs.getHitPoints(), rhs.getEnergyPoints(), rhs.getAtackDamage());
    }

    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() << " use a positive high fives request!" << std::endl;
}