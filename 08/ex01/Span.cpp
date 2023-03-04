/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:18 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 13:42:19 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) _n(0) {}

Span::Span(unsigned int n) : _n(n) {}


Span::Span( Span const & src)
{
    *this = src;
}

Span::~Span() {}

Span & Span::operator=(Span const & rhs)
{
    (void)rhs;
    return *this;
}

void Span::addNumber(unsigned int n)
{
    if (this->_myVector.size() > this->_n)
        throw std::out_of_range("You can't more fill the Span!");
    
    this->_myVector.push_back(n);
}

int Span::shortestSpan(void)
{
    if (this->_myVector.size() < 2)
        throw std::range_error("No span can be found!");

    
    std::sort(this->_myVector.begin(), this->_myVector.end());
    int diff = Span::longestSpan();
    int lastElement = *this->_myVector.begin();
    int aux = 0;

    std::vector<int>::const_iterator    it;
    std::vector<int>::const_iterator    ite = this->_myVector.end();
    for (it = this->_myVector.begin(); it != ite; ++it)
    {
        if (it == this->_myVector.begin())
            ++it;

        aux = *it;
        if (diff > aux - lastElement)
            diff = aux - lastElement;
        
        lastElement = aux;
    }

    return (diff);
}

int Span::longestSpan(void)
{
    if (this->_myVector.size() < 2)
        throw std::range_error("No span can be found!");
    
    int min = *std::min_element(this->_myVector.begin(), this->_myVector.end());
    int max = *std::max_element(this->_myVector.begin(), this->_myVector.end());

    return (max - min);
}

void Span::fillNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator last)
{
    //TODO

    this->_myVector.insert(this->_myVector.begin()+this->_myVector.size(), begin, last);
}
