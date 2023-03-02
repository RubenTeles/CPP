/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:49:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template< typename T>
void   swap(T &x, T &y)
{
    T aux;

    aux = y;
    y = x;
    x = aux;
}

template< typename T>
T   min(T x, T y)
{
    if (y > x)
        return x;
    return y;
}

template< typename T>
T   max(T x, T y)
{
    if (x > y)
        return x;
    return y;
}

#endif