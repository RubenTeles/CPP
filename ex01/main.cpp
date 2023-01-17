/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:42:50 by rteles            #+#    #+#             */
/*   Updated: 2023/01/16 23:59:18 by rteles           ###   ########.fr       */
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
	
	std::cin >> answer;

	return (answer);
}

std::string	showSearch(PhoneBook *phoneBook, std::string search = NULL)
{
	std::string	answer;
	(void)phoneBook;

	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|           My Awesome PhoneBook            |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|   INDEX  |   FIRST  |   LAST   | NICKNAME |" << std::endl;
	std::cout << "|          |   NAME   |   NAME   |          |" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	
	if (search != "")
		phoneBook->searchContact(search);
	else
		phoneBook->allContact();
	
	std::cout << "|__________|__________|__________|__________|" << std::endl;

	std::cout << "SEARCH: ";
	std::cin >> answer;

	return (answer);
}

void	showAdd(PhoneBook *phoneBook)
{
	std::string	firstName = "";
	std::string	lastName = "";
	std::string	nickName = "";
	std::string	phoneNumber = "";
	std::string	darkestSecret = "";

	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                ADD CONTACT                |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	
	std::cout << "First Name: ";
	std::cin >> firstName;
	
	std::cout << "Last Name: ";
	std::cin >> lastName;
	
	
	std::cout << "Nickname: ";
	std::cin >> nickName;
	
	std::cout << "Phone Number: ";
	std::cin >> phoneNumber;
	
	std::cout << "Darkest Secret: ";
	std::cin >> darkestSecret;

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