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

const char* Intern::UnknowFormException::what() const throw()
{
    return ("This Form don't exist!");
}

AForm * Intern::makeForm(std::string formName, std::string target)
{
    std::string	formList[3] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon",
	};

    for (int i = 0; i < 3; i++)
    {
        if (formList[i] == formName)
        {
            switch (i)
            {
                case 0:
                    return (new RobotomyRequestForm(target));
                case 1:
                    return (new ShrubberyCreationForm(target));
                case 2:
                    return (new PresidentialPardonForm(target));
            }
        }
    }
    throw UnknowFormException();
}
