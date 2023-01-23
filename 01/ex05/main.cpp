/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:45:44 by rteles            #+#    #+#             */
/*   Updated: 2023/01/17 21:53:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  *zombies;
    
    zombies = zombieHorde( 10, "Albert the Zombie");
    
    if (zombies == NULL)
        return (1);

    for (int i = 0; i < 10; i++)
        zombies[i].announce();

    delete[] zombies;
    return (0);
}