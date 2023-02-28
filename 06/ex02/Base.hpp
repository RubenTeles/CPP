/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:49:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base { 
    public: 
        virtual ~Base(void);

    Base * generate(void);
    void identify(Base* p);
    void identify(Base& p);
};

class A : public Base { };
class B : public Base { };
class C : public Base { };


#endif