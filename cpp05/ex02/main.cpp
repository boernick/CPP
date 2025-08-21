/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:20:15 by nick              #+#    #+#             */
/*   Updated: 2025/08/21 10:36:06 by nboer            ###   ########.fr       */
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

	PresidentialPardonForm x("huis");
	
	a.signForm(x);
	d.signForm(x);
	d.executeForm(x);
	
	RobotomyRequestForm y("lab");
	a.signForm(y);
	c.signForm(y);
	d.executeForm(y);
	
	ShrubberyCreationForm z("jungle");
	
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
}
