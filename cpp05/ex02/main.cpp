/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:20:15 by nick              #+#    #+#             */
/*   Updated: 2025/08/10 17:10:26 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat a("Hans", 15);
	Bureaucrat b("Piet", 30);
	
	PresidentialPardonForm x;
	PresidentialPardonForm y("huis");
		
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	
	a.signForm(y);
	b.signForm(y);
}
