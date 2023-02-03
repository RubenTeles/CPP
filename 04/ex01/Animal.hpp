/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 18:36:44 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string _type;
    
    public:
        Animal(void);
        Animal(std::string _type);
        Animal( Animal const & src);
        virtual ~Animal(void);

        Animal & operator=(Animal const & rhs);
        
        virtual void makeSound(void) const;
        std::string getType(void) const;

};

#endif