/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:20:15 by nick              #+#    #+#             */
/*   Updated: 2025/08/13 21:56:50 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat a("Hans", 140);
	Bureaucrat b("Piet", 30);
	Bureaucrat c("Joep", 10);
	Bureaucrat d("Geert", 1);

	PresidentialPardonForm x("huis");
	
	a.signForm(x);
	d.signForm(x);
	d.executeForm(x);
	
		
	RobotomyRequestForm y("lab");
	
	
	ShrubberyCreationForm z("jungle");
	
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
}
