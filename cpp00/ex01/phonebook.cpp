/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:40:39 by nboer             #+#    #+#             */
/*   Updated: 2025/03/02 18:49:40 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phonebook.hpp"

class Contact{
public:
	std::string	number;
	std::string	name;
	std::string	lastname;
	std::string	nickname;
	std::string	secret;

	Contact(){}

	void SetContact(){
		std::cout << "Name:" << std::endl;
		std::getline(std::cin, name);
		std::cout << "Last Name:" << std::endl;
		std::getline(std::cin, lastname);
		std::cout << "Number:" << std::endl;
		std::cin >> number;
		std::cin.ignore();
		std::cout << "Nickname:" << std::endl;
		std::getline(std::cin, nickname);
		std::cout << "Darkest secret:" << std::endl;
		std::getline(std::cin, secret);
	}

	std::string FormatColumn(std::string str){
		if (str.length() > 10)
			return (str.substr(0, 9).append("."));
		else
			return (str);
	}

	void ShowContact(int i){
		std::cout << "|";
		std::cout << "         " << i;
		std::cout << "|";
		std::cout << std::setw(10) << std::right << FormatColumn(name);
		std::cout << "|";
		std::cout << std::setw(10) << std::right << FormatColumn(lastname);
		std::cout << "|";
		std::cout << std::setw(10) << std::right << FormatColumn(nickname);
		std::cout << "|\n";
	}
};

class PhoneBook{
public:
	Contact	contact[8];
	int l;
	
	PhoneBook() : l(0) {}
	
	void AddContact(){
		if (l == 8)
			l = 0;
		contact[l].SetContact();
		std::cout << "Contact created" << std::endl;
		l++;
	}

	void ListContacts(){
		std::cout << HEADER << std::endl;
		for (int i = 0; i < l; i++)
			contact[i].ShowContact(i);
	}

	void SearchContact(std::string name)
	{
		int found = 0;

		for (int i = 0; i <= l; i++)
		{
			if (name == contact[i].name)
			{
				std::cout << HEADER << std::endl;
				contact[i].ShowContact(i);
				found = 1;
			}
		}
		if (!found)
			std::cout << "Contact not found" << std::endl;
	}
};

int main (void)
{
	int 			exit = 0;
	std::string		arg;
	PhoneBook		pb;

	while (exit == 0)
	{
		std::cout << "Phonebook: enter one of the following cmds: ADD, SEARCH, EXIT" << std::endl;
		std::getline (std::cin, arg);
		if (arg == "ADD")
			pb.AddContact();
		if (arg == "SEARCH")
		{	
			pb.ListContacts();
			std::cout << "Search for contact name:" << std::endl;
			std::getline(std::cin, arg);
			pb.SearchContact(arg);
		}
		if (arg == "EXIT")
			exit = 1;
	}
	return (0);
}
