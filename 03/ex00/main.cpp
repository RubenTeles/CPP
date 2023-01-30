/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:16:56 by rteles            #+#    #+#             */
/*   Updated: 2023/01/30 23:26:29 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap player1("Gustavo");
    ClapTrap player2("FelizBerto");

    std::cout << std::endl << "Turn 1:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(2);
    player2.beRepaired(2);

    std::cout << std::endl << "Turn 2:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(4);
    player2.attack(player1.getName());
    player1.takeDamage(7);
    std::cout << "CRITICAL!!!" << std::endl;

    std::cout << std::endl << "Turn 3:" << std::endl << std::endl;
    player1.beRepaired(2);
    player2.attack(player1.getName());
    player1.takeDamage(5);

    player1.beRepaired(4);

    std::cout << std::endl << player2.getName() << " is the Winner!" << std::endl << std::endl;
}