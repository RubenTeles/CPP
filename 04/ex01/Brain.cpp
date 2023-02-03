/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:18 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 13:42:19 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default Constructor!" << std::endl;
}

Brain::Brain( Brain const & src)
{
    *this = src;
}

Brain::~Brain() {
    std::cout << "Brain Destructor!" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs)
{
    if (this != &rhs)
    {
        //Todo
        //this->ideas = rhs.getIdeas();
    }

    return *this;
}
        
std::string Brain::getIdeas(void) const
{
    return "ola";
    //return this->ideas;
}
