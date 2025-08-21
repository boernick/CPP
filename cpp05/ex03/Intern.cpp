/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:08:30 by nboer             #+#    #+#             */
/*   Updated: 2025/08/21 17:07:33 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
	_form_class[0] = &ShrubberyCreationForm::create;
	_form_class[1] = &RobotomyRequestForm::create;
	_form_class[2] = &PresidentialPardonForm::create;
}

Intern::~Intern() {
	std::cout << "Intern deconstructor called" << std::endl;
}

Intern::Intern(Intern const &i) { 
	(void)i;
}

Intern &Intern::operator=(Intern const &src) { 
	(void)src;
	return (*this);
}

AForm* Intern::MakeForm(std::string name, std::string target){
	std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
		if (forms[i] == name)
		{	
			std::cout << "Intern creates " << forms[i] << std::endl;
			return ((*_form_class[i])(target));
		}
	std::cout << name << " is not a valid form class" << std::endl;
	return (NULL);
}
