/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 17:54:33 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): FragTrap(), ScavTrap()
{
    this->_name = "";
    std::cout << "DiamondTrap " << this->_name << " default summoned!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
    FragTrap temp;
    
    this->_hitPoints = temp.getHitPoints();
    this->_energyPoints = ScavTrap::getEnergyPoints();
    this->_atackDamage = temp.getAtackDamage();
    
    std::cout << "DiamondTrap " << this->_name << " was summoned!" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src): ClapTrap(src), FragTrap(src), ScavTrap(src)
{
    *this = src;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->_name << " was killed!" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
    if (this != &rhs)
    {
        FragTrap::operator=(rhs);
        ScavTrap::operator=(rhs);
    }

    return *this;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap my name is " << this->ClapTrap::_name << " for friends " << this->_name << "!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

std::string DiamondTrap::getNameDiamond(void) const
{
    return this->_name;
}