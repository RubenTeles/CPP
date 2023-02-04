/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:22:15 by rteles            #+#    #+#             */
/*   Updated: 2023/02/04 00:25:09 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_H
# define MateriaSource_H

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        std::string _type;
        
    public:
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};

#endif