/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:36:00 by rteles            #+#    #+#             */
/*   Updated: 2023/01/16 23:58:49 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

    PhoneBook::total = 0;
    for (int i = 0; i < 8; i++) {
        contacts[i] = Contact();
    }
    
    std::cout << "constructor called" << std::endl;
    return ;
}

PhoneBook::~PhoneBook( void ) {
    
    std::cout << "Destructor called" << std::endl;
    return ;
}

int PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
    if (PhoneBook::total == 8)
    {
        for (int i = 0; i < 7; i++)
        {
            this->contacts[i] = this->contacts[i + 1];
            this->contacts[i].editIndex(i);
        }
        this->contacts[7].editContact(7, firstName, lastName, nickname, phoneNumber, darkestSecret);

        return (1);
    }
    this->contacts[PhoneBook::total].editContact(total, firstName, lastName, nickname, phoneNumber, darkestSecret);
    PhoneBook::total += 1;
    return (0);
}

int PhoneBook::searchContact(std::string str)
{
    for (int i = 0; i < PhoneBook::total; i++)
    {
        this->contacts[i].searchAttribut(str);
    }
    return (0);
}

int PhoneBook::allContact(void)
{
    for (int i = 0; i < PhoneBook::total; i++)
    {
        this->contacts[i].getAttribut();
    }
    return (0);
}

int PhoneBook::totalContacts(void) const
{
    return (PhoneBook::total);
}

int PhoneBook::total = 0;