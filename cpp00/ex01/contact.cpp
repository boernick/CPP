/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:30:24 by nboer             #+#    #+#             */
/*   Updated: 2025/03/09 17:19:36 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() : _number(""), _name(""), _lastname(""), _nickname(""), _secret("") {}

int Contact::GetIndex() {
	return index;
}

const	std::string &Contact::GetName() const {
	return (_name);
}

void Contact::SetField(std::string &field, const std::string &fieldName){
	std::cout << fieldName << ":" << std::endl;
	std::getline(std::cin, field);
	if (field.empty()) {
		std::cout << "Cannot be empty" << std::endl;
		SetField(field, fieldName);
	}
}

void Contact::SetContact(int i){
	index = i;
	SetField(_name, "Name");
	SetField(_lastname, "Last Name");
	SetField(_number, "Number");
	SetField(_nickname, "Nickname");
	SetField(_secret, "Darkest Secret");
}

const std::string Contact::FormatColumn(std::string str) const {
	if (str.length() > 10)
		return (str.substr(0, 9).append("."));
	else
		return (str);
}

void Contact::ShowContact(int i){
	std::cout << "|";
	std::cout << "         " << i;
	std::cout << "|";
	std::cout << std::setw(10) << std::right << FormatColumn(_name);
	std::cout << "|";
	std::cout << std::setw(10) << std::right << FormatColumn(_lastname);
	std::cout << "|";
	std::cout << std::setw(10) << std::right << FormatColumn(_nickname);
	std::cout << "|\n";
}

void Contact::PrintContact(){
	std::cout << "\nName: " << _name << std::endl;
	std::cout << "Last Name: " << _lastname << std::endl;
	std::cout << "Number: " << _number << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Darkest secret: " << _secret << std::endl << std::endl;
}
