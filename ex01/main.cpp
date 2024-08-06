/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:31:32 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/06 13:52:35 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook *phonebook = new PhoneBook();
	std::string commandline;
	while (phonebook->GetExit() != 1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, commandline);
		if (commandline == "ADD")
			phonebook->AddContact();
		else if (commandline == "SEARCH")
			phonebook->SearchContact();
		else if (commandline == "EXIT")
			phonebook->Exit();
		else
			std::cout << "Invalid command" << std::endl;
	}
	delete phonebook;
	return 0;
}