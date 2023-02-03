/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:12:32 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 23:41:36 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : virtual public AAnimal
{
    private:
        Brain*      brain;

    public:
        Cat(void);
        Cat( Cat const & src);
        virtual ~Cat(void);

        Cat & operator=(Cat const & rhs);
        
        virtual void makeSound(void) const;
        
        std::string getIdea(int index) const;
        void    setIdea(int index, std::string idea);
};

#endif