/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:28:27 by rteles            #+#    #+#             */
/*   Updated: 2023/01/17 16:11:53 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
    private:

        std::string name;
    
    public:
        Zombie(std::string name);
        Zombie();
        ~Zombie();

        void announce( void );
        void setName( std::string name );
        
};

Zombie* zombieHorde( int N, std::string name );