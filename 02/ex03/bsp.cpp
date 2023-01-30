/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:00:04 by rteles            #+#    #+#             */
/*   Updated: 2023/01/30 16:54:19 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Method Barycentric
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float lambda1 = ((b.getY().toFloat() - c.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat())) / ((b.getY().toFloat() - c.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat()));
    float lambda2 = ((c.getY().toFloat() - a.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat()) + (a.getX().toFloat() - c.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat())) / ((b.getY().toFloat() - c.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat()));
    float lambda3 = 1 - lambda1 - lambda2;
    
    if (lambda1 > 0 && lambda1 < 1 && lambda2 > 0 && lambda2 < 1 && lambda3 > 0 && lambda3 < 1)
        return true;
    return false;
}
