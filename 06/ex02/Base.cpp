/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:18 by rteles            #+#    #+#             */
/*   Updated: 2023/02/28 16:34:31 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base * Base::generate(void)
{
    int random = 0;

    std::srand(time(NULL));
    while (random <= 0 || random > 3)
        random = 1 + (std::rand() % 3);

    switch (random)
    {
        case 1:
            std::cout << "Random Choise: A" << std::endl;
            return new A();
        case 2:
            std::cout << "Random Choise: B" << std::endl;
            return new B();
        default:
            std::cout << "Random Choise: C" << std::endl;
            return new C();
    }
}

void Base::identify(Base* p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "It's A type!" << std::endl; 
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "It's B type!" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "It's C type!" << std::endl; 
}

void Base::identify(Base& p)
{
    try
    {
        A & a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "It's A type!" << std::endl; 
    }
    catch(const std::exception& e)
    {
    }

    try
    {
        B & b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "It's B type!" << std::endl; 
    }
    catch(const std::exception& e)
    {
    }
    
    try
    {
        C & c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "It's C type!" << std::endl; 
    }
    catch(const std::exception& e)
    {
    }
}
