/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:18:55 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 16:31:25 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

#include "ExTree.h"

class Cure : virtual public AMateria
{
    public:
        Cure(void);
        Cure( Cure const & src);
        ~Cure(void);

        Cure & operator=(Cure const & rhs);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif