/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:16:50 by nboer             #+#    #+#             */
/*   Updated: 2025/08/31 15:38:59 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void) {
	//integers
	Array<int> empty_array;
	std::cout << "Size array: " << empty_array.size() << std::endl;
	
	Array<int> array_5(5);
	Array<int> array_3(3);
	try {
		array_3[4] = 0;
		array_5[4] = 0;
	}
	catch (const Array<int>::OutsideBoundsException &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	array_3 = array_5;
	
	try {
		array_5[4] = 1;
	}
	catch (const Array<int>::OutsideBoundsException &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	for (unsigned int i = 0; i < array_3.size(); i++)
		std::cout << array_3[i];
	std::cout << std::endl;
	for (unsigned int i = 0; i < array_5.size(); i++)
		std::cout << array_5[i];
	std::cout << std::endl;

	//strings
	........

	
}
