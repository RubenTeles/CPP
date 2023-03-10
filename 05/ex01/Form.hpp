/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:49:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeRequired;
        int const           _gradeExecute;
        Form();

    public:
        Form(std::string name, int required, int execute);
        Form( Form const & src);
        virtual ~Form(void);

        Form & operator=(Form const & rhs);

        std::string getName(void) const;
        bool        isSigned(void) const;
        int         getGradeRequired(void) const;
        int         getGradeExecute(void) const;
    
        void        beSigned(Bureaucrat *bur);
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeIsSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif