/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:49:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template< typename T>
typename T::iterator   easyfind(T a, int b)
{
    typename T::iterator it;

    it = std::find(a.begin(), a.end(), b);
    if (it != a.end())
        return it;
    else
        throw std::invalid_argument("Element Not Found!");
}

#endif