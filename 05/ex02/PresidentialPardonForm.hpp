/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:12:32 by rteles            #+#    #+#             */
/*   Updated: 2023/02/22 22:41:02 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
    private:
        std::string target;
        PresidentialPardonForm(void);

    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm( PresidentialPardonForm const & src);
        virtual ~PresidentialPardonForm(void);

        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

        virtual void    execute(Bureaucrat const & executor) const;
};

#endif