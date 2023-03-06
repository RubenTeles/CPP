/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:49:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
# define MutantStack_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template< typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
 
    public:
        MutantStack(void);
        MutantStack( MutantStack const & src);
        ~MutantStack();

        MutantStack & operator=(MutantStack const & rhs);

        typename MutantStack<T>::container_type::iterator    begin(void);
        typename MutantStack<T>::container_type::iterator    end(void);
};


template< typename T>
MutantStack<T>::MutantStack(void) 
{}

template< typename T>
MutantStack<T>::MutantStack( MutantStack const & src)
{
    *this = src;
}

template< typename T>
MutantStack<T>::~MutantStack() 
{}



template< typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & rhs)
{
	if (this != &rhs)
        std::stack<T>::operator=(rhs);

    return *this;
}


template< typename T>
typename MutantStack<T>::container_type::iterator    MutantStack<T>::begin(void)
{
    return this->c.begin();
}

template< typename T>
typename MutantStack<T>::container_type::iterator    MutantStack<T>::end(void)
{
    return this->c.end();
}

#endif