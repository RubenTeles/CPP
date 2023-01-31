/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:16:56 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 18:06:04 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    FragTrap player1("Super_Gustavo");
    ScavTrap player2("Super_FelisBerto");
    DiamondTrap player3("GOKU");

    std::cout << std::endl;
    player3.whoAmI();
    std::cout << "DiamondTrap:" << std::endl
    << "Hit Points: " << player3.getHitPoints() << std::endl
    << "Energy Points: " << player3.getEnergyPoints() << std::endl
    << "Atack Damage: " << player3.getAtackDamage() << std::endl;

    std::cout << std::endl << "Turn 1:" << std::endl << std::endl;
    player3.highFivesGuys();
    player1.highFivesGuys();
    player2.guardGate();
    player3.guardGate();

    std::cout << std::endl << "Turn 2:" << std::endl << std::endl;
    player3.attack(player1.getName());
    player1.takeDamage(player3.getAtackDamage());
    player2.attack(player3.getName());
    player3.takeDamage(player2.getAtackDamage());
    player1.attack(player3.getName());
    player3.takeDamage(player1.getAtackDamage());

    std::cout << std::endl << "Turn 3:" << std::endl << std::endl;
    player3.attack(player1.getName());
    player1.takeDamage(player3.getAtackDamage());
    player2.attack(player3.getName());
    player3.takeDamage(player2.getAtackDamage());
    player1.attack(player3.getName());
    player3.takeDamage(player1.getAtackDamage());

    std::cout << std::endl << "Turn 4:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(player1.getAtackDamage());
    player2.attack(player1.getName());
    player1.takeDamage(player2.getAtackDamage());

    std::cout << std::endl << player2.getName() << " is the Winner!" << std::endl << std::endl;
}