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

#ifndef NEWMATERIA_H
# define NEWMATERIA_H

#include "ExTree.h"

class NewMateria : virtual public AMateria
{
    public:
        NewMateria(void);
        NewMateria(std::string type);
        NewMateria( NewMateria const & src);
        virtual ~NewMateria(void);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif