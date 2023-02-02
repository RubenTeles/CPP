/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:00:04 by rteles            #+#    #+#             */
/*   Updated: 2023/02/02 17:04:01 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	areaTriangle(Point const a, Point const b, Point const c)
{
	return (((b.getY().toFloat() - c.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat()) + (c.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat())));
}

//Method Barycentric
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float trianguloArea = areaTriangle(a, b, c);
	float lambda1 = areaTriangle(point, b, c) / trianguloArea;
	float lambda2 = areaTriangle(point, c, a) / trianguloArea;
	float lambda3 = 1 - lambda1 - lambda2;
	
	if (lambda1 > 0 && lambda1 < 1 && lambda2 > 0 && lambda2 < 1 && lambda3 > 0 && lambda3 < 1)
		return true;
	return false;
}

//If any lambda is <= 0 or >= 1 the pointer is out of the triangle or in vertex or on edge.