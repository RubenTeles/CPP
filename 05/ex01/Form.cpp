/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:18 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 17:40:29 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name(""), _signed(0), _gradeRequired(1), _gradeExecute(1)
{
    std::cout << "Form default Constructor!" << std::endl;
}

Form::Form(std::string name, int required, int execute) : _name(name), _signed(0),
                                                          _gradeRequired(required),
                                                          _gradeExecute(execute)
{
    if (required > 150 || execute > 150)
        throw GradeTooLowException();
    else if (required < 1 || execute < 1)
        throw GradeTooHighException();
    
    std::cout << "Form Constructor!" << std::endl;
}

Form::Form( Form const & src):  _name(src.getName()),
                                _signed(src.isSigned()),
                                _gradeRequired(getGradeRequired()),
                                _gradeExecute(getGradeExecute())
{
    *this = src;
}

Form::~Form() {
    std::cout << "Form Destructor!" << std::endl;
}

Form & Form::operator=(Form const & rhs)
{
    if (this != &rhs)
    {
        std::string& name = const_cast<std::string&>(this->_name);
        int& required = const_cast<int&>(this->_gradeRequired);
        int& execute = const_cast<int&>(this->_gradeExecute);

        name = rhs.getName();
        this->_signed = rhs.isSigned();
        required = rhs.getGradeRequired();
        execute = rhs.getGradeExecute();
    }

    return *this;
}

std::string Form::getName(void) const
{
    return this->_name;
}

bool Form::isSigned(void) const
{
    return this->_signed;
}

int Form::getGradeRequired(void) const
{
    return this->_gradeRequired;
}

int Form::getGradeExecute(void) const
{
    return this->_gradeExecute;
}

void Form::beSigned(Bureaucrat *bur)
{
    if (bur->getGrade() > this->_gradeRequired)
    {
        bur->signForm(this->getName(), false, "the form grade is too High!");
        throw GradeTooLowException();
    }
    else if (this->_signed)
    {
        bur->signForm(this->getName(), false, "is already signed!");
        throw GradeIsSignedException();
    }
    else
    {
        bur->signForm(this->getName(), true, "");
        this->_signed = 1;
    }
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "The Grade is too Hight. (Less than 1).";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "The Grade is too Low. (More than 150).";
}

const char* Form::GradeIsSignedException::what() const throw()
{
    return "The Grade is already Signed!";
}

std::ostream & operator<<(std::ostream & o, Form const & i)
{
    o << i.getName() << ", Form Grade Required: " << i.getGradeRequired() 
    << ", Form Grade Execute: " << i.getGradeExecute() << ".";

    return o;
}