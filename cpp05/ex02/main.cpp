/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:20:15 by nick              #+#    #+#             */
/*   Updated: 2025/08/09 13:15:35 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	Bureaucrat a("Hans", 40);
	Bureaucrat b("Piet", 50);
	
	AForm x;
	AForm y("Submission Form", 45, 45);
	
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	
	a.signForm(y);
	b.signForm(y);
}
