/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:18 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 21:19:35 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(1)
{
    std::cout << "Bureaucrat default Constructor!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    
    std::cout << "Bureaucrat Constructor!" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src)
{
    *this = src;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor!" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    if (this != &rhs)
    {
        std::string& name = const_cast<std::string&>(this->_name);

        this->_grade = rhs.getGrade();
        name = rhs.getName();
    }

    return *this;
}

std::string Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
    if (this->_grade - 1 < 1)
        throw GradeTooHighException();
    this->_grade -= 1;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    this->_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("The Grade is too Hight. (Less than 1).");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("The Grade is too Low. (More than 150).");
}


std::ostream & operator<<(std::ostream & o, Bureaucrat const & i)
{
    o << i.getName() << ", bureaucrat grade " << i.getGrade();

    return o;
}