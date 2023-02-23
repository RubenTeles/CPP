/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 22:56:27 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5)
{
    this->target = "";
    std::cout << "PresidentialPardonForm Constructor!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 72, 45)
{
    this->target = target;
    std::cout << "PresidentialPardonForm Constructor!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src): AForm(src)
{
    std::cout << "PresidentialPardonForm Clonned!" << std::endl;
    
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor!" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    executor.executeForm(*this);

    std::cout << this->target << ", pardoned by Zaphod Beeblebrox." << std::endl;
}