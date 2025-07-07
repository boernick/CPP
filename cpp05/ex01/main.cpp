/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:20:15 by nick              #+#    #+#             */
/*   Updated: 2025/07/07 22:18:17 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	const Bureaucrat* B1 = new Bureaucrat("Hans"); 
	
	try
	{
	}
	catch (std::exception & e)
	{
	}
	
	std::cout << B1->getName() << std::endl; 
	std::cout << B1->getGrade() << std::endl;
	
	return 0;
}