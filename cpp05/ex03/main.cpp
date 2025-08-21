/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:20:15 by nick              #+#    #+#             */
/*   Updated: 2025/08/21 17:12:09 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat b("Hans", 50);
	Intern unpaid_intern;
	AForm *f = NULL;
	std::string forms[3] = {"PresidentialPardonForm",
		 "RobotomyRequestForm", "ShrubberyCreationForm"};
	
	// unvalid form
	std::cout << std::endl;
	unpaid_intern.MakeForm("unvalid_form", "unknown");
	
	// create form, sign and execute
	std::cout << std::endl;
	f = unpaid_intern.MakeForm(forms[0], "test");
	b.signForm(*f);
	b.executeForm(*f);
	delete f;

	f = unpaid_intern.MakeForm(forms[1], "test");
	b.signForm(*f);
	b.executeForm(*f);
	delete f;

	f = unpaid_intern.MakeForm(forms[2], "test");
	b.signForm(*f);
	b.executeForm(*f);
	delete f;
}
