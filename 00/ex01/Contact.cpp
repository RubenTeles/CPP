/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:36:00 by rteles            #+#    #+#             */
/*   Updated: 2023/01/23 14:16:56 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include <sstream>


Contact::Contact(void)
{
    std::cout << "Constructor called" << std::endl;
    return ;
}

Contact::~Contact( void ) {
    
    std::cout << "Destructor called" << std::endl;
    return ;
}

void Contact::editContact(int index, std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
    this->index = index;
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
	this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;

    return ;
}

void Contact::editIndex(int index)
{
	this->index = index;

    return ;
}

void	ft_word(std::string str)
{
	int n;
	int spaces;

	n = str.length();
	if (n > 10)
	{
		for (int i = 0; i < 9; i++)
		{
			std::cout << str[i];
		}
		std::cout << ".";
	}
	else
	{
		spaces = 10 - n;
		for (int i = 0; i < spaces; i++)
			std::cout << " ";
		std::cout << str;
	}
	std::cout << "|";
	return ;
}

void	Contact::getAttribut(void) const
{
	std::cout << "|";
    std::ostringstream s;
    s << this->index;
    const std::string num_string(s.str());
	ft_word(num_string);
	ft_word(this->firstName); 
	ft_word(this->lastName);
	ft_word(this->nickname);
	std::cout << std::endl;

	return ;
}

int	Contact::searchAttribut(std::string str)
{
	if (str.find_first_not_of("0123456789") == std::string::npos)
	{
    	std::ostringstream s;
    	s << this->index;
    	const std::string num_string(s.str());
		if (str == num_string)
		{
			std::cout << std::endl << "Index: " << this->index << std::endl <<
			"First Name: " << this->firstName << std::endl <<
			"Last Name: " << this->lastName << std::endl <<
			"Nickname: " << this->nickname << std::endl <<
			"Phone Number: " << this->phoneNumber << std::endl <<
			"Darkest Secret: " << this->darkestSecret << std::endl << std::endl;
			
			return (1);
		}	
	}
	return (0);
}