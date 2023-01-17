/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:29:23 by rteles            #+#    #+#             */
/*   Updated: 2023/01/17 15:13:50 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*It creates a zombie, name it, and return it so you can use it outside of the function scope*/
Zombie* newZombie( std::string name )
{
    Zombie *myZombie = new Zombie(name);

    return (myZombie);
}
