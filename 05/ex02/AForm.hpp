/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:27:24 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 16:49:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeRequired;
        int const           _gradeExecute;
        AForm();

    public:
        AForm(std::string name, int required, int execute);
        AForm( AForm const & src);
        virtual ~AForm(void);

        AForm & operator=(AForm const & rhs);

        std::string getName(void) const;
        bool        isSigned(void) const;
        int         getGradeRequired(void) const;
        int         getGradeExecute(void) const;
    
        void        beSigned(Bureaucrat *bur);
        void        execute(Bureaucrat const & executor) const;
        
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

        class GradeIsNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream & operator<<(std::ostream & o, AForm const & i);

#endif