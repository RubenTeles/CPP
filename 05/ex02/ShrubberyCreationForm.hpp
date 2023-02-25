/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:12:32 by rteles            #+#    #+#             */
/*   Updated: 2023/02/22 22:55:41 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : virtual public AForm
{
    private:
        std::string target;
        ShrubberyCreationForm(void);

    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm( ShrubberyCreationForm const & src);
        virtual ~ShrubberyCreationForm(void);

        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

        virtual void    execute(Bureaucrat const & executor) const;

        class FailToOpenException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif