/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:40:39 by nboer             #+#    #+#             */
/*   Updated: 2025/03/07 14:58:35 by nboer            ###   ########.fr       */
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
	int			index;

	Contact(){}

	void SetField(std::string &field, const std::string &fieldName) {
		std::cout << fieldName << ":" << std::endl;
		std::getline(std::cin, field);
		if (field.empty()) {
			std::cout << "Cannot be empty" << std::endl;
			SetField(field, fieldName);
		}
	}
	
	void SetContact(int i){
		index = i;
		SetField(name, "Name");
		SetField(lastname, "Last Name");
		SetField(number, "Number");
		SetField(nickname, "Nickname");
		SetField(secret, "Darkest Secret");
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

	void PrintContact(){
		std::cout << "\nName: " << name << std::endl;
		std::cout << "Last Name: " << lastname << std::endl;
		std::cout << "Number: " << number << std::endl;
		std::cout << "Nickname: " << nickname << std::endl;
		std::cout << "Darkest secret: " << secret << std::endl << std::endl;
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
		contact[l].SetContact(l);
		std::cout << "Contact created" << std::endl;
		l++;
	}

	void ListContacts(){
		std::cout << HEADER << std::endl;
		for (int i = 0; i < 8; i++)
		{
			if (!contact[i].name.empty())
				contact[i].ShowContact(i);
		}
	}

	void SearchContact(std::string index)
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
		if (contact[0].name == "")
		{
			std::cout << EMPTY_PHONEBOOK << std::endl;
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			if (indx == contact[i].index)
			{
				contact[i].PrintContact();
				found = 1;
			}
		}
		if (!found)
			std::cout << INVALID_INDEX << std::endl;
	}
};

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
