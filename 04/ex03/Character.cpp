/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 13:35:41 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int Character::_maxInventory = 0;

Character::Character(void)
{
    this->_name = "";
    for (int i = 0; i < 4; i++)
        this->_invetory[i] = NULL;

    std::cout << "Character Default Constructor!" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_invetory[i] = NULL;
    
    std::cout << "Character Constructor!" << std::endl;
}

Character::Character( Character const & src)
{
    *this = src;
}

Character::~Character()
{
    for (int i = 0; i < Character::_maxInventory; i++)
        delete this->_invetory[i];
        
    std::cout << "Character Destructor!" << std::endl;
}

Character & Character::operator=(Character const & rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        for (int i = 0; i < 4; i++)
            this->_invetory[i] = rhs.getInventory(i);
    }

    return *this;
}

std::string const & Character::getName(void) const
{
    return this->_name;
}

void    Character::equip(AMateria* m)
{
    if (Character::_maxInventory < 4)
    {
        this->_invetory[_maxInventory] = m;
        Character::_maxInventory += 1;

        std::cout << "The Materia " << m->getType() << " is equip in Inventory!" << std::endl; 
        
        return ;
    }
    
    std::cout << "The Inventory is Full!" << std::endl;
}

void    Character::unequip(int idx)
{
    //TODO
    //Need delete

    if (_maxInventory > idx)
    {
        std::cout << "The Materia " << this->_invetory[idx]->getType() << " is unequip in the Inventory!" << std::endl; 

        this->_invetory[idx] = NULL;

        for (int i = idx; i < 3; i++)
        {
            this->_invetory[i] = this->_invetory[i + 1];
            this->_invetory[i + 1] = NULL;
        }
        Character::_maxInventory -= 1;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (_maxInventory > idx)
        this->_invetory[idx]->use(target);
}

AMateria*    Character::getInventory(int idx) const
{
    if (_maxInventory > idx)
        return this->_invetory[idx];
    return NULL;
}