/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:13:40 by nboer             #+#    #+#             */
/*   Updated: 2025/03/09 16:36:50 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

int main (void)
{
	int 			exit = 0;
	std::string		arg;
	PhoneBook		pb;

	while (exit == 0)
	{
		std::cout << PHONEBOOK_PROMPT << std::endl;
		std::getline (std::cin, arg);
		if (arg == "ADD")
			pb.AddContact();
		if (arg == "SEARCH")
		{	
			pb.ListContacts();
			std::cout << SEARCH_PROMPT << std::endl;
			std::getline(std::cin, arg);
			if (!arg.empty())
				pb.SearchContact(arg);
		}
		if (arg == "EXIT")
		{
			std::cout << EXIT_PROMPT << std::endl;
			exit = 1;
		}
	}
	return (0);
}
