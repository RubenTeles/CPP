/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:46:10 by rteles            #+#    #+#             */
/*   Updated: 2023/02/02 17:09:46 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) 
{
    Point a(0, 0);
    Point b(2, 2);
    Point c(3, 0);
    Point point1(2, 1);
    Point point2(2, 3);
    Point point3(0, 0);

    if (bsp(a, b, c, point1))
        std::cout << "Point 1 is inside the triangle" << std::endl;
    else
        std::cout << "Point 1 is outside the triangle" << std::endl;
    
    if (bsp(a, b, c, point2))
        std::cout << "Point 2 is inside the triangle" << std::endl;
    else
        std::cout << "Point 2 is outside the triangle" << std::endl;
    
    if (bsp(a, b, c, point3))
        std::cout << "Point 3 is inside the triangle" << std::endl;
    else
        std::cout << "Point 3 is outside the triangle" << std::endl;
    
    return 0;
    
}
