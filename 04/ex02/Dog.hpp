/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:18:55 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 16:31:25 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : virtual public AAnimal
{
    private:
        Brain*      brain;

    public:
        Dog(void);
        Dog( Dog const & src);
        virtual ~Dog(void);

        Dog & operator=(Dog const & rhs);
        
        virtual void makeSound(void) const;

        std::string getIdea(int index) const;
        void    setIdea(int index, std::string idea);
};

#endif