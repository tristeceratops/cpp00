/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:10:15 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/06 13:52:14 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void AddContact();
		void SearchContact();
		void ShowContact();
		int	 GetExit();
		void Exit();
	private:
		Contact contacts[8];
		int contact_count;
		int exit;
		int	oldest_contact;
};