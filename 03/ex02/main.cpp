/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:16:56 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 18:05:46 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap player1("Super_Gustavo");
    ScavTrap player2("Super_FelisBerto");

    std::cout << "FragTrap:" << std::endl
    << "Hit Points: " << player2.getHitPoints() << std::endl
    << "Energy Points: " << player2.getEnergyPoints() << std::endl
    << "Atack Damage: " << player2.getAtackDamage() << std::endl;

    std::cout << std::endl << "Turn 1:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(player1.getAtackDamage());
    player2.guardGate();

    std::cout << std::endl << "Turn 2:" << std::endl << std::endl;
    player1.highFivesGuys();
    player2.guardGate();

    std::cout << std::endl << "Turn 3:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(player1.getAtackDamage());
    player2.attack(player2.getName());
    player1.takeDamage(player2.getAtackDamage());

    std::cout << std::endl << player2.getName() << " is the Winner!" << std::endl << std::endl;
}