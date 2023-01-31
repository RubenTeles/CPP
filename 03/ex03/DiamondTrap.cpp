/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 11:45:33 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): FragTrap(), ScavTrap()
{
    this->nameClapTrap = "_clap_name";
    std::cout << "DiamondTrap " << this->nameClapTrap << " default summoned!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
    this->nameClapTrap = name + "_clap_name";
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = energyPoints;
    this->atackDamage = atackDamage;
    std::cout << "DiamondTrap " << this->nameClapTrap << " was summoned!" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src):  FragTrap(src), ScavTrap(src)
{
    *this = src;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->nameClapTrap << " was killed!" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
    if (this != &rhs)
    {
        this->nameClapTrap = rhs.getNameClapTrap();
        FragTrap::operator=(rhs);
        ScavTrap::operator=(rhs);
    }

    return *this;
}

void DiamondTrap::whoAmI(void)
{
    return ;
    //std::cout << "DiamondTrap my is " << this->ClapTrap::name << " and " << this->nameClapTrap << "!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

std::string DiamondTrap::getNameClapTrap(void) const
{
    return this->nameClapTrap;
}