/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:12:32 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 23:01:47 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern : virtual public AForm
{
    public:
        Intern(void);
        Intern( Intern const & src);
        virtual ~Intern(void);

        Intern & operator=(Intern const & rhs);

        AForm * makeForm(std::string formName, std::string target);
        
        class UnknowFormException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif