/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:49:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
# define Span_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
    private:
        std::vector<int>    _myVector;
        unsigned int        _n;

    public:
        Span(void);
        Span(unsigned int n);
        Span( Span const & src);
        ~Span(void);

        Span & operator=(Span const & rhs);
        
        void addNumber(unsigned int n);
        int shortestSpan(void);
        int longestSpan(void);

        void fillNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator last);
};

#endif