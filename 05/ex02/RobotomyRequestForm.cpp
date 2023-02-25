/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/02/23 11:42:40 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45)
{
    this->target = "";
    std::cout << "RobotomyRequestForm Constructor!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
    std::cout << "RobotomyRequestForm Constructor!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src): AForm(src)
{
    std::cout << "RobotomyRequestForm Clonned!" << std::endl;
    
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor!" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}

const char* RobotomyRequestForm::RobotTomyExecuteFailException::what() const throw()
{
    return "The execute failed!";
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    executor.executeForm(*this);

    std::cout << "* Makes some drilling noises *" << std::endl;
    std::srand(time(NULL));
    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized!" << std::endl;
    else
    {
        std::cout << this->target << ", robotomy failed!" << std::endl;
        throw  RobotTomyExecuteFailException();
    }
}