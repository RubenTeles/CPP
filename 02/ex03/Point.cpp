/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:10:13 by rteles            #+#    #+#             */
/*   Updated: 2023/01/30 16:10:09 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(float const x, float const y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point( Point const & src)
{
    *this = src;
}

Point::~Point() {}

Point & Point::operator=(Point const & rhs)
{
    if (this != &rhs)
    {
        Fixed *x = const_cast<Fixed*>(&this->x); 
        Fixed *y = const_cast<Fixed*>(&this->y);

        *x = rhs.getX();
        *y = rhs.getY();
    }

    return *this;
}
//const_cast = change a const for pointer for change the value

Fixed   Point::getX(void) const
{
    return this->x;
}

Fixed   Point::getY(void) const
{
    return this->y;
}
