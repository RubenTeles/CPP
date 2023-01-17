/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:50:46 by rteles            #+#    #+#             */
/*   Updated: 2023/01/17 16:24:17 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>
#include <string>

Zombie* zombieHorde(  int N, std::string name )
{
    if (N < 0)
        return (NULL);

    Zombie* zombies = new Zombie[N];
    
    for (int i = 0; i < N; i++)
    {
        std::ostringstream s;
        s << i;
        const std::string i_as_string(s.str());
        zombies[i].setName(name + " " + i_as_string);
    }

    return (zombies);
}