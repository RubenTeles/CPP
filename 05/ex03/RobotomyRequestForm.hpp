/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:12:32 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 23:01:43 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm( RobotomyRequestForm const & src);
        virtual ~RobotomyRequestForm(void);

        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
};

#endif