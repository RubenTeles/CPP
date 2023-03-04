/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/03/04 17:10:01 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void    test(Span &test)
{
    try {

        std::cout << test.shortestSpan() << std::endl;
        std::cout << test.longestSpan() << std::endl;

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
int main()
{
    Span sp1 = Span(5);
    
    sp1.addNumber(6);
    sp1.addNumber(3);
    sp1.addNumber(17);
    sp1.addNumber(9);
    sp1.addNumber(11);
    
    test(sp1);

    Span sp2 = Span(5);
    
    sp2.addNumber(6);
    
    test(sp2);

    
    return 0;
}