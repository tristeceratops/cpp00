/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:51:33 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/07 16:29:55 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
	_nbAccounts++;
	this->_accountIndex = getNbAccounts() - 1;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	this->_accountIndex = getNbAccounts() - 1;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";" << "created"
	<< std::endl;
	
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";" << "closed"
	<< std::endl;
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_totalNbDeposits -= this->_nbDeposits;
	_totalNbWithdrawals -= this->_nbWithdrawals;
}

int Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount()
{
	return t::_totalAmount ;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";" 
	<< "total:" << _totalAmount << ";" 
	<< "deposits:" << _totalNbDeposits << ";" 
	<< "withdrawals:" << _totalNbWithdrawals 
	<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" 
	<< "p_amount:" << this->_amount << ";" 
	<< "deposit:" << deposit << ";" 
	<< "amount:" << this->_amount + deposit << ";"
	<< "nb_deposits:" << this->_nbDeposits + 1
	<< std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	if (checkAmount())
	{
		std::cout << "index:" << this->_accountIndex << ";" 
		<< "p_amount:" << this->_amount << ";"
		<< "withdrawal:" << withdrawal << ";" 
		<< "amount:" << this->_amount - withdrawal << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals + 1
		<< std::endl;
	}
	else
	{
		std::cout << "index:" << this->_accountIndex << ";" 
		<< "withdrawal:refused"<< std::endl;
		this->_amount += withdrawal;
		_totalAmount += withdrawal;
		this->_nbWithdrawals--;
		_totalNbWithdrawals--;
	}
	return (true);
}

int Account::checkAmount() const
{
	return (this->_amount >= 0);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" 
	<< "amount:" << this->_amount << ";" 
	<< "deposits:" << this->_nbDeposits << ";" 
	<< "withdrawals:" << this->_nbWithdrawals 
	<< std::endl;
}

void Account::_displayTimestamp()
{
	time_t timestamp;
	tm	*tm;
	char buffer[20];

	time(&timestamp);
	tm = localtime(&timestamp);
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", tm);
	std::cout << buffer;
}