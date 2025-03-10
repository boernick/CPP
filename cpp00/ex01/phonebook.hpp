/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:40:28 by nboer             #+#    #+#             */
/*   Updated: 2025/03/09 16:38:57 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"
# include <iostream>
# include <iomanip>
# include <string.h>

# define HEADER "|     index|      name|  lastname|  nickname|"
# define EMPTY_PHONEBOOK "Error: phonebook empty"
# define INVALID_INPUT "Error: invalid input"
# define INVALID_INDEX "Error: invalid search index"
# define PHONEBOOK_PROMPT "Phonebook: enter one of the following cmds: ADD, SEARCH, EXIT"
# define SEARCH_PROMPT "\nSearch for contact index:"
# define EXIT_PROMPT "\nPhonebook deleted. Just like your social life.\n"

class PhoneBook{
private:
	Contact	contact[8];
	int l;

public:
	PhoneBook() : l(0) {}
	void AddContact();
	void ListContacts();
	void SearchContact(std::string index);
};

#endif
