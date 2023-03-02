/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:49:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template< typename T>
class Array
{
    private:
        T*  _array;
        unsigned int _n;

    public:
        Array< T>(void) : _array(new T[0]), _n(0) { };
        Array< T>(unsigned int n) : _array(new T[n]), _n(n) { };
        Array< T>( Array< T> const & src) 
        { 
            this->_array = new T[src._n];    
            
            *this = src;
        };
        ~Array< T>() { delete[] this->_array; };

        Array & operator=( Array< T > const & rhs)
        {
            if (this != &rhs)
            {
                this->_n = rhs._n;

                for (int i = 0; i < (int)this->_n; i++)
                    this->_array[i] = rhs._array[i];
            }

            return *this;
        };

        T& operator[]( unsigned int index)
        {
            if (index >= this->_n)
                throw std::out_of_range("The index is out of array size!");
            return this->_array[index];
        }

        unsigned int size(void) const { return this->_n; };
};

#endif