/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:51:33 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/06 17:27:28 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account()
{
	
}

Account::Account(int initial_deposit)
{
	
}

Account::~Account()
{
	
}

int Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount()
{
	return Account::_totalAmount ;
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
	
}

void Account::makeDeposit(int deposit)
{
	
}

bool Account::makeWithdrawal(int withdrawal)
{

}

int Account::checkAmount() const
{
}

void Account::displayStatus() const
{
}

void Account::_displayTimestamp()
{
	
}