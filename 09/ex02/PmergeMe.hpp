/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:57:22 by rteles            #+#    #+#             */
/*   Updated: 2023/03/13 22:22:15 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>

class PmergeMe
{
    private:
        std::list<unsigned int>     _list;
        std::vector<unsigned int>   _vector;
        double                      _timeList;
        double                      _timeVector;
        PmergeMe();
        void    sortedList(void);
        void    sortedVector(void);

    public:
        PmergeMe(char **numbers);
        PmergeMe( PmergeMe const & src);
        ~PmergeMe();

        PmergeMe & operator=(PmergeMe const & rhs);

        void    show(char **argv);
};

#endif