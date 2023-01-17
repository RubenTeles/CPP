/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:31:53 by rteles            #+#    #+#             */
/*   Updated: 2023/01/17 14:36:21 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
        
/*It creates a zombie, name it, and the zombie announces itself.*/
void randomChump( std::string name )
{
	Zombie	myZombie(name);

	myZombie.announce();

	return ;
}
