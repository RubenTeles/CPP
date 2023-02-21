/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 13:35:41 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

int MateriaSource::_learnCapacity = 0;

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        this->_learnMateria[i] = NULL;
    
    std::cout << "MateriaSource Constructor!" << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const & src)
{
    *this = src;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < MateriaSource::_learnCapacity; i++)
        delete this->_learnMateria[i];

    std::cout << "MateriaSource Destructor!" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
            this->_learnMateria[i] = rhs._learnMateria[i];
    }

    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (MateriaSource::_learnCapacity < 4)
    {
        this->_learnMateria[_learnCapacity] = m;

        std::cout << "The Materia " << m->getType() << " is learn!" << std::endl; 
  
        MateriaSource::_learnCapacity += 1;

        return ;
    }
    
    std::cout << "He can't learn more!" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < MateriaSource::_learnCapacity; i++)
    {
        if (type == this->_learnMateria[i]->getType())
            return this->_learnMateria[i]->clone();
    }
    return (0);
}