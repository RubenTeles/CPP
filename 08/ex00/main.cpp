/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/03/02 23:07:29 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <deque>
#include "easyfind.hpp"

template< typename T>
void    test(T a, int b)
{
    try {
        easyfind(a, b);
        std::cout  << b << " " << "Element Found!" << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << b << " " << e.what() << std::endl;
    }
}

int main( void )
{
    std::cout << "---- LIST ----" << std::endl << std::endl;

    std::list<int> lst;

    lst.push_back(32);
    lst.push_back(9);
    lst.push_back(12);
    lst.push_back(7);
    
    test(lst, 9);
    test(lst, 1);
    
    std::cout << std::endl << std::endl << "---- VECTOR ----" << std::endl << std::endl;
    
    std::vector<int> vtr;

    vtr.push_back(32);
    vtr.push_back(9);
    vtr.push_back(12);
    vtr.push_back(7);

    test(vtr, 5);
    test(vtr, 7);

    std::cout << std::endl << std::endl << "---- DEQUE ----" << std::endl << std::endl;
    
    std::deque<int> dq;

    dq.push_back(32);
    dq.push_back(9);
    dq.push_back(12);
    dq.push_back(7);

    test(dq, 8);
    test(dq, 32);
    
    return 0;
}