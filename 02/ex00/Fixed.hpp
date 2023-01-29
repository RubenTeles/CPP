/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:46:33 by rteles            #+#    #+#             */
/*   Updated: 2023/01/29 21:30:24 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
    private:
        int					rawBits;
		static const int	factionalBit = 8;
    
    public:
        Fixed(void);
        Fixed( Fixed const & src);
        ~Fixed(void);
        
        Fixed & operator=(Fixed const & rhs);

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif