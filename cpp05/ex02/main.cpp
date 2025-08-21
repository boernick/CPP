/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:20:15 by nick              #+#    #+#             */
/*   Updated: 2025/08/21 11:50:46 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat a("Hans", 140);
	Bureaucrat b("Piet", 30);
	Bureaucrat c("Joep", 10);
	Bureaucrat d("Geert", 1);

	// test Presidential Pardon
	PresidentialPardonForm x("huis");
	a.signForm(x);
	d.signForm(x);
	d.executeForm(x);
	
	// test Robotomy Request
	RobotomyRequestForm y("lab");
	a.signForm(y);
	c.signForm(y);
	d.executeForm(y);
	
	// test Shrubbery Creation
	ShrubberyCreationForm z("jungle");
	a.signForm(z);
	c.signForm(z);
	a.executeForm(z);
	d.executeForm(z);
	std::cout << std::endl;
	
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
	std::cout << std::endl;
}
