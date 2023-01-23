/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:42:50 by rteles            #+#    #+#             */
/*   Updated: 2023/01/23 14:01:55 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

std::string showCommands(void)
{
	std::string	answer;
	
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                 COMMANDS                  |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|    ADD           SEARCH           EXIT    |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "COMMAND: ";
	
	std::getline(std::cin, answer);

	return (answer);
}

std::string	showSearch(PhoneBook *phoneBook, std::string search = NULL)
{
	std::string	answer;
	
	if (search != "" && search != "SEARCH")
	{
		phoneBook->searchContact(search);
	}
	else
	{
		std::cout << " ___________________________________________" << std::endl;
		std::cout << "|                                           |" << std::endl;
		std::cout << "|           My Awesome PhoneBook            |" << std::endl;
		std::cout << "|___________________________________________|" << std::endl;
		std::cout << "|          |          |          |          |" << std::endl;
		std::cout << "|   INDEX  |   FIRST  |   LAST   | NICKNAME |" << std::endl;
		std::cout << "|          |   NAME   |   NAME   |          |" << std::endl;
		std::cout << "|__________|__________|__________|__________|" << std::endl;
		
		phoneBook->allContact();
		
		std::cout << "|__________|__________|__________|__________|" << std::endl;	
	}

	std::cout << "SEARCH: ";

	std::getline(std::cin, answer);

	return (answer);
}

void	errorEmpty(std::string label)
{
	std::cout << "ERROR!" << std::endl << label << " is empty!" << std::endl;
	return ;
}

void	showAdd(PhoneBook *phoneBook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                ADD CONTACT                |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	
	
	std::cout << "First Name: ";
	std::getline(std::cin, firstName);
	if (firstName.empty())
	{
		errorEmpty("First Name");
		return ;
	}
	
	std::cout << "Last Name: ";
	std::getline(std::cin, lastName);
	if (lastName.empty())
	{
		errorEmpty("Last Name");
		return ;
	}
	
	std::cout << "Nickname: ";
	std::getline(std::cin, nickName);
	if (nickName.empty())
	{
		errorEmpty("NickName");
		return ;
	}

	
	std::cout << "Phone Number: ";
	std::getline(std::cin, phoneNumber);
	if (phoneNumber.empty())
	{
		errorEmpty("Phone Number");
		return ;
	}

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, darkestSecret);
	if (darkestSecret.empty())
	{
		errorEmpty("Darkest Secret");
		return ;
	}

	phoneBook->addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);

	return ;
	
}

int main(void)
{
    PhoneBook   phoneBook;
	std::string	option;
	std::string	search;

	option = showCommands();

	while (1)
	{
		search = "";
		if (option == "SEARCH")
		{
			while (search != "ADD" && search != "EXIT")
				search = showSearch(&phoneBook, search);
		}
		if (option == "ADD" || search == "ADD")
			showAdd(&phoneBook); 
		else if (option == "EXIT" || search == "EXIT")
			break ;
		option = showCommands();
	}
    return (0);
}