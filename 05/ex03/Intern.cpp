/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 22:56:27 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void): AForm()
{
    std::cout << "Intern Constructor!" << std::endl;
}

Intern::Intern( Intern const & src): AForm(src)
{
    std::cout << "Intern Clonned!" << std::endl;
    
    *this = src;
}

Intern::~Intern() {
    std::cout << "Intern Destructor!" << std::endl;
}

Intern & Intern::operator=(Intern const & rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}

AForm * Intern::makeForm(std::string formName, std::string target)
{
    /*void (AForm::*create[3])(void) = {
		new PresidentialPardonForm(),
		&Harl::info,
		&Harl::warning,
	};*/

    std::string	levelList[3] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon",
	};
    
    //std::cout << "Intern creates " << form << std::endl;
    //return *this;
}
