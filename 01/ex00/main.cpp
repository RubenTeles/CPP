/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:45:44 by rteles            #+#    #+#             */
/*   Updated: 2023/01/17 15:04:21 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  *zombieOne;
    
    zombieOne = newZombie("Albert");
    randomChump("Nicki Minaj");
    
    delete(zombieOne);

    return (0);
}