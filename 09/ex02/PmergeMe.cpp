/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:57:22 by rteles            #+#    #+#             */
/*   Updated: 2023/03/13 20:10:12 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}


PmergeMe::PmergeMe(char **numbers)
{

}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe( PmergeMe const & src)
{
    *this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    if (this != &rhs)
    {

    }
    
    return *this;
}

void PmergeMe::result(void)
{
    if (this->calculate.size() == 1)
        std::cout << this->calculate.top() << std::endl; 
}