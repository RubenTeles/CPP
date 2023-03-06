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
class MutantStack {
    private:
        std::stack<int>    _stack;

    public:
        MutantStack(void);
        MutantStack( MutantStack const & src);
        ~MutantStack(void);

        MutantStack & operator=(MutantStack const & rhs);

        void        push(T val);
        int         top(void); //TODO
        void        pop(void);
        size_t      size(void);
        size_t      begin(void);//TODO
        size_t      end(void);  //TODO
};

#endif