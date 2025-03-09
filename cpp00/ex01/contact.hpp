/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:54:35 by nboer             #+#    #+#             */
/*   Updated: 2025/03/09 17:58:59 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact{
private:
	std::string	_number;
	std::string	_name;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_secret;
	int			index;
	const	std::string FormatColumn(std::string str) const;
	void	SetField(std::string &field, const std::string &fieldName);
public:
	Contact();
	Contact(std::string name, std::string lastname, std::string number, 
		std::string nickname, std::string secret);
	const	std::string &GetName() const;
	int		GetIndex();
	void	SetContact(int i);
	void	PrintContact();
	void	ShowContact(int i);
};

#endif
