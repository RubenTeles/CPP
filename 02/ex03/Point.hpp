/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:10:13 by rteles            #+#    #+#             */
/*   Updated: 2023/01/30 16:51:42 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    
    public:
        Point(void);
        Point(float const x, float const y);
        Point( Point const & src);
        ~Point(void);
        
        Point & operator=(Point const & rhs);

        Fixed getX(void) const;
        Fixed getY(void) const;
        void setX(const Fixed& x);
        void setY(const Fixed& y);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif