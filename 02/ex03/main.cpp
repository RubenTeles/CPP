/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:46:10 by rteles            #+#    #+#             */
/*   Updated: 2023/01/30 16:52:56 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) 
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(1, 4);
    Point point1(1, 2);
    Point point2(5, 5);
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
