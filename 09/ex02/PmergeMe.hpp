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

class PmergeMe
{
    private:
        std::list<int> list;
        std::vector<int> list;
        PmergeMe();

    public:
        PmergeMe(char *numbers);
        PmergeMe( PmergeMe const & src);
        ~PmergeMe();

        PmergeMe & operator=(PmergeMe const & rhs);

        void    result(void);
};

#endif