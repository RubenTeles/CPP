/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:06:26 by rteles            #+#    #+#             */
/*   Updated: 2023/01/24 12:55:12 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl created!" << std::endl << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destroyed!" << std::endl;
}

void Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< std::endl << std::endl;
	return ;
}

void Harl::info( void )
{
	std::cout << "[INFO]" << std::endl <<
	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl << std::endl;

	return ;
}

void Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl <<
	"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
	<< std::endl << std::endl;

	return ;
}

void Harl::error( void )
{	
	std::cout << "[ERROR]" << std::endl <<
	"This is unacceptable! I want to speak to the manager now."
	<< std::endl << std::endl;

	return ;
}

void Harl::complain( std::string level )
{
	void (Harl::*eval[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	std::string	levelList[4] = {
		"debug",
		"info",
		"warning",
		"error",
	};
	
	int index = 0;
	for (index = 0; index < 4; index++)
	{
		if (levelList[index] == level)
			break ;
	}
	
	switch (index)
	{
		case 0:
			(this->*eval[0])();
			break;
		case 1:
			(this->*eval[1])();
			break;
		case 2:
			(this->*eval[2])();
			break;
		case 3:
			(this->*eval[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
			break;
	}
	
}