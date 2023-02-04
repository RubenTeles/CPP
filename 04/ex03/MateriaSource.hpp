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

#include "ExTree.h"

class MateriaSource : public IMateriaSource
{
    protected:
        AMateria*   _learnMateria[4];
        static int  _learnCapacity;
        
    public:
        MateriaSource(void);
        MateriaSource( MateriaSource const & src);
        virtual ~MateriaSource(void);

        MateriaSource & operator=(MateriaSource const & rhs);

        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);


        void learnNewMateria(std::string type);
};

#endif