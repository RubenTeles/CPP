/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:12:32 by rteles            #+#    #+#             */
/*   Updated: 2023/02/23 11:41:33 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
    private:
        std::string target;
        RobotomyRequestForm(void);

    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm( RobotomyRequestForm const & src);
        virtual ~RobotomyRequestForm(void);

        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
        
        virtual void    execute(Bureaucrat const & executor) const;

        class RobotTomyExecuteFailException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif