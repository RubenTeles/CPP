/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:36:00 by rteles            #+#    #+#             */
/*   Updated: 2023/01/16 23:59:28 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {

    private:

    	static int	total;
        Contact		contacts[8];

    public:

	    PhoneBook( void );
        ~PhoneBook( void );

		int	addContact(std::string firstName, std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret);
		int	searchContact(std::string str);
		int	allContact(void);
		int	totalContacts(void) const;
};

#endif