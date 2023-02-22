/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:12:32 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 23:01:47 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm( PresidentialPardonForm const & src);
        virtual ~PresidentialPardonForm(void);

        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
};

#endif