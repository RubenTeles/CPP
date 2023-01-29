/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:36:00 by rteles            #+#    #+#             */
/*   Updated: 2023/01/29 18:47:57 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string.h>

class Contact {

	private:
	
	    int		    index;
	    std::string firstName;
		std::string lastName;
		std::string nickname;
	    std::string phoneNumber;
	    std::string darkestSecret;
	
	public:
	
		Contact( void );
	    ~Contact( void );
	
	
		void		editContact( int index, std::string firstName, std::string lastName,
		std::string nickname, std::string phoneNumber, std::string darkestSecret );
		void		editIndex(int index);
		void		getAttribut(void) const;
		int			searchAttribut(std::string str);

};

#endif