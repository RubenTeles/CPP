/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:22:15 by rteles            #+#    #+#             */
/*   Updated: 2023/02/04 15:25:05 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include "ExTree.h"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria*   _invetory[4];
        static int  _maxInventory;
        Character(void);
        
    public:
        Character(std::string name);
        Character( Character const & src);
        virtual ~Character(void);
        
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

        AMateria*    getInventory(int idx) const;
};

#endif