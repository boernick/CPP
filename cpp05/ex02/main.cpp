/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:20:15 by nick              #+#    #+#             */
/*   Updated: 2025/08/03 17:47:52 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a;
	Bureaucrat b("Hans", 149);
	Bureaucrat c("Wim", 2);
	
	try{
		c.incGrade();
		std::cout << c << std::endl;
		c.incGrade();
	}	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	try{
		b.decGrade();
		std::cout << b << std::endl;
		b.decGrade();
	}	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat d("Joep", 151);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat e("Piet", 0);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << a << std::endl;
	std::cout << c << std::endl;
	a = c;
	std::cout << a << std::endl;
	
	return 0;
}
