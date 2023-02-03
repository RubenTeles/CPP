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

Cat::Cat(void): Animal("Cat")
{
    this->brain = new Brain();

    std::cout << "Cat Constructor!" << std::endl;
}

Cat::Cat( Cat const & src): Animal(src)
{
    delete this->brain;

    *this = src;
}

Cat::~Cat() {
    std::cout << "Cat Destructor!" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }

    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "Miau!" << std::endl;
}