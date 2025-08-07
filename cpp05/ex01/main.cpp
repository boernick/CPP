/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:20:15 by nick              #+#    #+#             */
/*   Updated: 2025/08/07 19:05:55 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat a("Hans", 40);
	Bureaucrat b("Piet", 50);
	
	Form x;
	Form y("Submission Form", 45, 45);
	
	std::cout << x << std::endl;
	
	
}
