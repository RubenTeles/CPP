/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 11:20:05 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void    testArray(int numberAnimals)
{
	std::cout << std::endl << std::endl << " --- Array Test --- [" << numberAnimals << "]" << std::endl << std::endl;

    Animal  *animals[numberAnimals];

    for (int i = 0; i < numberAnimals; i++)
    {
        if (i % 2)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
        std::cout << animals[i]->getType() << " " << std::endl << std::endl;
    }
    for (int i = numberAnimals - 1; i > -1; i--)
    {
        animals[i]->makeSound();
        delete animals[i];
        std::cout << std::endl;
    }
}

void    testLeak(void)
{
	std::cout << std::endl << std::endl << " --- Leak Test --- " << std::endl << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;//should not create a leak
    delete i;
}

void testCopy(void)
{
    std::cout << std::endl << std::endl << " --- Copy Test --- " << std::endl << std::endl;

    Dog d1;
    d1.setIdea(0, "I am Dog!");
    std::cout<< "Type: " << d1.getType() << std::endl << "Idea: " << d1.getIdea(0) << std::endl << std::endl;
    
    Dog d2(d1);
    std::cout << "Type: " << d2.getType() << std::endl << "Idea: " << d2.getIdea(0) << std::endl << std::endl;
    Cat c1;

    c1.setIdea(0, "I am Cat!");
    std::cout << "Type: " << c1.getType() << std::endl << "Idea: " << c1.getIdea(0) << std::endl << std::endl;
    
    Cat c2(c1);
    std::cout << "Type: " << c2.getType() << std::endl << "Idea: " << c2.getIdea(0) << std::endl << std::endl;
}

int main()
{
    testLeak();
    testArray(6);
	testCopy();
    
    return (0);
}
