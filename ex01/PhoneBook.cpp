/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:09:28 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/09 12:54:33 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_count = 0;
	this->oldest_contact = 0;
	this->exit = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::AddContact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string dark_secret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	if (first_name.length() == 0)
		return (std::cout << "Empty fields not allow" << std::endl, (void)0);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	if (last_name.length() == 0)
	return (std::cout << "Empty fields not allow" << std::endl, (void)0);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.length() == 0)
	return (std::cout << "Empty fields not allow" << std::endl, (void)0);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	if (phone_number.length() == 0)
	return (std::cout << "Empty fields not allow" << std::endl, (void)0);
	std::cout << "Enter dark secret: ";
	std::getline(std::cin, dark_secret);
	if (dark_secret.length() == 0)
	return (std::cout << "Empty fields not allow" << std::endl, (void)0);
	if (this->contact_count < 8)
	{
		this->contacts[this->contact_count] = Contact(first_name, last_name, nickname, phone_number, dark_secret);
		this->contact_count++;
	}
	else
	{
		this->contacts[this->oldest_contact] = Contact(first_name, last_name, nickname, phone_number, dark_secret);
		this->oldest_contact++;
		if (this->oldest_contact == 8)
			this->oldest_contact = 0;
	}
}

void PhoneBook::SearchContact()
{
	int index;
	std::string input;

	if (this->contact_count == 0)
	{
		std::cout << "No contacts available" << std::endl;
		return;
	}
	this->ShowContact();
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (input.length() == 1 && isdigit(input[0]))
	{
		index = input[0] - '0';
		if (index >= 0 && index < this->contact_count)
		{
			std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
			std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
			std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
			std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Dark secret: " << this->contacts[index].getDarkSecret() << std::endl;
		}
		else
			std::cout << "Invalid index" << std::endl;
	}
	else
		std::cout << "Invalid input" << std::endl;
}

void PhoneBook::ShowContact()
{
	std::cout
	<< std::setw(10) << "index" << "|" 
	<< std::setw(10) << "first name" << "|" 
	<< std::setw(10) << "last name" << "|" 
	<< std::setw(10) << "nickname" 
	<< std::endl;
	for (int i = 0; i < this->contact_count; i++)
	{
		std::cout 
			<< std::setw(10) << i << "|"
    		<< std::setw(10) << (this->contacts[i].getFirstName().length() > 10 ? this->contacts[i].getFirstName().substr(0, 9) + "." : this->contacts[i].getFirstName()) << "|"
   			<< std::setw(10) << (this->contacts[i].getLastName().length() > 10 ? this->contacts[i].getLastName().substr(0, 9) + "." : this->contacts[i].getLastName()) << "|"
    		<< std::setw(10) << (this->contacts[i].getNickname().length() > 10 ? this->contacts[i].getNickname().substr(0, 9) + "." : this->contacts[i].getNickname())
			<< std::endl;
	}
}

void PhoneBook::Exit()
{
	std::cout << "Exiting..." << std::endl;
	this->exit = 1;
}

int	PhoneBook::GetExit()
{
	return (this->exit);
}

