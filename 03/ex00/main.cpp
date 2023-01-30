/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:16:56 by rteles            #+#    #+#             */
/*   Updated: 2023/01/30 23:58:00 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap player1("Gustavo");
    ClapTrap player2("FelizBerto");

    std::cout << std::endl << "Turn 1:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(0);
    player2.beRepaired(2);

    std::cout << std::endl << "Turn 2:" << std::endl << std::endl;
    player1.attack(player2.getName());
    player2.takeDamage(0);
    player2.attack(player1.getName());
    player1.takeDamage(0);
    
    std::cout << std::endl << "Turn 3:" << std::endl << std::endl;
    player1.beRepaired(2);
    player2.attack(player1.getName());
    player1.takeDamage(0);

    std::cout << std::endl << "Is a Draw!" << std::endl << std::endl;
}