/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:16:56 by rteles            #+#    #+#             */
/*   Updated: 2023/01/30 23:55:48 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap player1("Gustavo");
    ScavTrap player2("Super_Robot");

    std::cout << std::endl << "Turn 1:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(0);
    player2.guardGate();

    std::cout << std::endl << "Turn 2:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(0);
    player2.attack(player1.getName());
    player1.takeDamage(20);

    player1.beRepaired(4);

    std::cout << std::endl << player2.getName() << " is the Winner!" << std::endl << std::endl;
}