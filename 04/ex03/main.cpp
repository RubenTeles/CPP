/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:46:08 by rteles            #+#    #+#             */
/*   Updated: 2023/02/22 14:34:01 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExTree.h"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new NewMateria("fire"));
    src->learnMateria(new NewMateria("water"));
    src->learnMateria(new NewMateria("wind"));
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire");
    me->equip(tmp);
    tmp = src->createMateria("water");
    me->equip(tmp);
    me->unequip(0);
    me->unequip(0);
    tmp = src->createMateria("ice");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);

    std::cout << std::endl;
    std::cout << std::endl;
    
    delete bob;
    delete me;
    delete src;

    return 0;
}