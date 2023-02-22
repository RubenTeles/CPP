/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:12:32 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 23:00:56 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm( ShrubberyCreationForm const & src);
        virtual ~ShrubberyCreationForm(void);

        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
};

#endif