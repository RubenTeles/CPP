/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:28:27 by rteles            #+#    #+#             */
/*   Updated: 2023/01/17 16:11:53 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

class Harl
{
    private:
    
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    
    public:

        Harl();
        ~Harl();

        void complain( std::string level );
        
};
