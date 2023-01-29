/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:28:27 by rteles            #+#    #+#             */
/*   Updated: 2023/01/29 21:33:22 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
    private:

        std::string name;
    
    public:
        Zombie(std::string name);
        ~Zombie();

        void announce( void );
        
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif