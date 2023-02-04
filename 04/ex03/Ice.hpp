/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:12:32 by rteles            #+#    #+#             */
/*   Updated: 2023/02/04 00:36:52 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"
#include "Brain.hpp"

class Ice : virtual public AMateria
{
    public:
        Ice(void);
        Ice( Ice const & src);
        virtual ~Ice(void);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif