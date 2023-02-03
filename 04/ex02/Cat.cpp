/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 17:53:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): AAnimal("Cat")
{
    this->brain = new Brain();

    std::cout << "Cat Constructor!" << std::endl;
}

Cat::Cat( Cat const & src): AAnimal(src)
{
    this->brain = new Brain();

    std::cout << "Cat Clonned!" << std::endl;
    
    *this = src;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat Destructor!" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
        for (int i = 0; i < 100; i++)
            this->brain->setIdea(i, rhs.brain->getIdea(i));
    }

    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "Miau!" << std::endl;
}

std::string Cat::getIdea(int index) const
{
    return this->brain->getIdea(index);
}

void Cat::setIdea(int index, std::string idea)
{
    this->brain->setIdea(index, idea);
}
