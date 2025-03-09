/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:40:39 by nboer             #+#    #+#             */
/*   Updated: 2025/03/09 16:37:14 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phonebook.hpp"

void PhoneBook::AddContact(){
	if (l == 8)
		l = 0;
	contact[l].SetContact(l);
	std::cout << "Contact created" << std::endl;
	l++;
}

void PhoneBook::ListContacts(){
	std::cout << HEADER << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!contact[i].GetName().empty())
			contact[i].ShowContact(i);
	}
}

void PhoneBook::SearchContact(std::string index)
{
	int found = 0;
	int indx;
	
	if (index.length() == 1 && index[0] >= '0' && index[0] < '8')
		indx = index[0] - '0';
	else
	{
		std::cout << INVALID_INPUT << std::endl;
		return;
	}
	if (contact[0].GetName() == "")
	{
		std::cout << EMPTY_PHONEBOOK << std::endl;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (!contact[i].GetName().empty() && indx == contact[i].GetIndex())
		{
			contact[i].PrintContact();
			found = 1;
			break;
		}
	}
	if (!found)
		std::cout << INVALID_INDEX << std::endl;
}
