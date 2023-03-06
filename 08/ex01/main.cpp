/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/03/06 00:14:42 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void    testShortestLongest(Span &test)
{
    try {

        std::cout << test.shortestSpan() << std::endl;
        std::cout << test.longestSpan() << std::endl;

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void    testRangeIterator(Span &test, std::vector<int> &vector)
{
    try {
    
        test.fillNumbers(vector.begin(), vector.end());

        std::cout << test.shortestSpan() << std::endl;
        std::cout << test.longestSpan() << std::endl;

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void    testAddNumber(Span &test, int number)
{
    try {
            
        test.addNumber(number);

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_large_range_numbers()
{
	unsigned int n = 100001; 
	Span sp = Span(n);

	for (unsigned int i = 0; i < n; i++)
        testAddNumber(sp, i);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main()
{
    std::cout << "----------- Test Add Numbers -----------" << std::endl << std::endl;
    
    Span sp1 = Span(5);
    
    testAddNumber(sp1, 6);
    testAddNumber(sp1, 3);
    testAddNumber(sp1, 17);
    testAddNumber(sp1, 9);
    testAddNumber(sp1, 11);
    
    testShortestLongest(sp1);

    std::cout << std::endl << "----------- Test Exceed Add Numbers -----------" << std::endl << std::endl;

    testAddNumber(sp1, 3);

    std::cout << std::endl << "----------- Test Add 100000 Numbers -----------" << std::endl << std::endl;

    test_large_range_numbers();
    
    std::cout << std::endl << "----------- Test Add Just 1 Number -----------" << std::endl << std::endl;

    Span sp2 = Span(5);
    
    testAddNumber(sp2, 6);
    
    testShortestLongest(sp2);

    std::cout << std::endl << "----------- Test Range of Iterators -----------" << std::endl << std::endl;

    int numbers[] = { 23 , 42 , 34 , 10};
    std::vector<int> vectorNumbers;
    
    testRangeIterator(sp2, vectorNumbers);

    vectorNumbers.insert(vectorNumbers.end(), numbers, numbers + 4);
    
    testRangeIterator(sp2, vectorNumbers);
    
    testAddNumber(sp2, 3);

    std::cout << std::endl << "----------- Test Exceeds Range of Iterators -----------" << std::endl << std::endl;

    Span sp3 = Span(3);
    
    testRangeIterator(sp3, vectorNumbers);

    return 0;
}