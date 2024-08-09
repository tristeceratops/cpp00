/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:11:59 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/09 11:35:59 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_H
# define CONTACT_H
# include "PhoneBook.h"

class Contact
{
public:
	Contact();
	Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkSecret);
	~Contact();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getDarkSecret();

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkSecret;
};

#endif