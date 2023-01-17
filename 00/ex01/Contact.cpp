/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:36:00 by rteles            #+#    #+#             */
/*   Updated: 2023/01/16 23:58:42 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "Contact.hpp"
#include <cstdlib>
#include <cstdio>


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
		for (int i = 0; i < 10; i++)
		{
			std::cout << str[i];
		}
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
	char	num_string[32];
	
	std::cout << "|";
	sprintf(num_string, "%d", this->index);
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
		const char* num_char = str.c_str();
		if (std::atoi(num_char) == this->index)
		{
			this->getAttribut();
			return (0);
		}	
	}
	if (str == this->firstName || str == this->lastName || str == this->nickname)
		this->getAttribut();
	return (0);
}