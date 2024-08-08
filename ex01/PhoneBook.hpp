/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:10:15 by ewoillar          #+#    #+#             */
/*   Updated: 2024/08/08 11:02:00 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include "PhoneBook.h"
# include "Contact.hpp"

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

#endif