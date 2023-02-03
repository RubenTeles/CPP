/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 23:43:01 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    const WrongAnimal* wAnimal = new WrongAnimal();
    const WrongAnimal* wCat = new WrongCat();
    
    std::cout << std::endl << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wCat->getType() << " " << std::endl << std::endl;
    
    i->makeSound(); //will output the cat sound!
    j->makeSound();

    wAnimal->makeSound();
    wCat->makeSound();

    std::cout << std::endl;

    delete i;
    delete j;
    delete wAnimal;
    delete wCat;

    return 0;
}