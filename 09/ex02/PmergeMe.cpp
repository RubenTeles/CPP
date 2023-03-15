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
    int i = 0;
    long number;

    while (numbers[++i])
    {
        int j = -1;

        while (numbers[i][++j])
        {
            if (!isdigit(numbers[i][j]) || j > 10)
            {
                throw std::invalid_argument("Error: the argument is invalid.");
                return ;
            }
        }
        number = std::atof(numbers[i]);
        if (number > 4294967295)
        {
            throw std::out_of_range("Error: the number is out of range.");
            return ;
        }
        this->_list.push_back(std::atof(numbers[i]));
        this->_vector.push_back(std::atof(numbers[i]));
    }
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

void PmergeMe::sortedList(void)
{
    clock_t start, end;

    start = clock();
  
    this->_list.sort();

    end = clock();
	this->_timeList = (double)(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::sortedVector(void)
{
    clock_t start, end;

    start = clock();
  
    std::sort(this->_vector.begin(), this->_vector.end());

    end = clock();
	this->_timeVector = (double)(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::show(char **argv)
{
    this->sortedList();
    this->sortedVector();
    
    std::cout << "Before: ";

    int i = 0;

    while (argv[++i])
        std::cout << " " << argv[i];
    
    std::cout << std::endl;

    std::cout << "After:  " ;
    
    std::vector<unsigned int>::const_iterator    it;
    for (it = this->_vector.begin(); it != this->_vector.end(); ++it)
        std::cout << " " << *it;

    std::cout << std::endl;

    std::cout << std::fixed << "Time to process a range of " << i - 1 << " elements with std::list : " << this->_timeList << " seconds" << std::endl;
    std::cout << std::fixed << "Time to process a range of " << i - 1 << " elements with std::vector : " << this->_timeVector << " seconds" << std::endl;
}