/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 23:36:30 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
    protected:
        std::string _type;
    
    public:
        AAnimal(void);
        AAnimal(std::string _type);
        AAnimal( AAnimal const & src);
        virtual ~AAnimal(void);

        AAnimal & operator=(AAnimal const & rhs);
        
        virtual void makeSound(void) const = 0;
        std::string getType(void) const;

};

#endif