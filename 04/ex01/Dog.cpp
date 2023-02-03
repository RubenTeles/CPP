/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 17:53:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
    this->brain = new Brain();

    std::cout << "Dog Constructor!" << std::endl;
}

Dog::Dog( Dog const & src): Animal(src)
{
    this->brain = new Brain();
    
    std::cout << "Dog Clonned!" << std::endl;

    *this = src;
}

Dog::~Dog() {

    delete this->brain;

    std::cout << "Dog Destructor!" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
        for (int i = 0; i < 100; i++)
            this->brain->setIdea(i, rhs.brain->getIdea(i));
    }
    
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "Au au!" << std::endl;
}

std::string Dog::getIdea(int index) const
{
    return this->brain->getIdea(index);
}

void Dog::setIdea(int index, std::string idea)
{
    this->brain->setIdea(index, idea);
}
