/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:16:50 by nboer             #+#    #+#             */
/*   Updated: 2025/09/06 15:27:09 by nboer            ###   ########.fr       */
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
	Array<std::string> str_array(2);
	Array<std::string> cpy_array(1);
	str_array[0] = "Some";
	str_array[1] = "string";
	cpy_array = str_array;
	std::cout << std::endl;
	std::cout << cpy_array[0] << " " << cpy_array[1] << std::endl;
	cpy_array[0] = "And another";
	std::cout << cpy_array[0] << " " << cpy_array[1] << std::endl;
	std::cout << std::endl;

	Array<Array<int> > obj_array(2);
	obj_array[0] = array_5;
	obj_array[1] = array_3;
	for (int i = 0; i < 5; i++)
		std::cout << i << ": " << obj_array[0][i] << std::endl;
}
