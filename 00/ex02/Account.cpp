/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:29:43 by rteles            #+#    #+#             */
/*   Updated: 2023/01/17 00:11:23 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "Account.hpp"

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

/*accounts:8; total:21524; deposits:8; withdrawals:0*/
void	Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << Account::_nbAccounts << ";" <<
	"total:" << Account::_totalAmount << ";" <<
	"deposits:" << Account::_totalNbDeposits << ";" <<
	"withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;


	std::cout << "index:" << this->_accountIndex << ";" <<
	"amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	std::cout << "index:" << this->_accountIndex << ";" <<
	"amount:" << this->_amount << ";closed" << std::endl;
}

/*index:0; p_amount:42; deposit:5; amount:47; nb_deposits:1*/
void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits += 1;
	
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;


	std::cout << "index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->_amount - deposit << ";" <<
	"deposit:" << deposit << ";" <<
	"amount:" << this->_amount << ";" <<
	"nb_deposits:" << this->_nbDeposits << std::endl;
}

/*index:0; p_amount:47; withdrawal:refused
  index:1; p_amount:819; withdrawal:34; amount:785; nb_withdrawals:1
*/
bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "index:" << this->_accountIndex << ";" <<
		"p_amount:" << this->_amount << ";" <<
		"withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;

	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;

	std::cout << "index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->_amount + withdrawal << ";" <<
	"withdrawal:" << withdrawal << ";" <<
	"amount:" << this->_amount << ";" <<
	"nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

/*index:0; amount:47; deposits:1; withdrawals:0*/
void	Account::displayStatus(void) const
{
	std::cout << "index:" << this->_accountIndex << ";" <<
	"amount:" << this->_amount << ";" <<
	"deposits:" << this->_nbDeposits << ";" <<
	"withdrawals:" << this->_nbWithdrawals << std::endl;
}
