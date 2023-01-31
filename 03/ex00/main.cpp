/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:16:56 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 18:05:09 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap player1("Gustavo");
    ClapTrap player2("FelizBerto");

    std::cout << "ClapTrap:" << std::endl
    << "Hit Points: " << player2.getHitPoints() << std::endl
    << "Energy Points: " << player2.getEnergyPoints() << std::endl
    << "Atack Damage: " << player2.getAtackDamage() << std::endl;

    std::cout << std::endl << "Turn 1:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(player1.getAtackDamage());
    player2.beRepaired(2);

    std::cout << std::endl << "Turn 2:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(player1.getAtackDamage());
    player2.attack(player1.getName());
    player1.takeDamage(player2.getAtackDamage());
    
    std::cout << std::endl << "Turn 3:" << std::endl << std::endl;
    player1.beRepaired(2);
    player2.attack(player1.getName());
    player1.takeDamage(player2.getAtackDamage());

    std::cout << std::endl << "Is a Draw!" << std::endl << std::endl;
}