/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:37:07 by nboer             #+#    #+#             */
/*   Updated: 2025/09/06 18:09:39 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void){
	int i;
	std::list<int>	list;
	std::list<int>	empty_list;
	
	list.push_front(10);
	list.push_front(20);
	list.push_front(30);

	try {
		i = easyfind(list, 30);
		std::cout << "value found : " << i << std::endl;
	}
	catch (ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		i = easyfind(list, 50);
		std::cout << "Value found : " << i << std::endl;
	}
	catch (ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		i = easyfind(empty_list, 30);
		std::cout << "Value found : " << i << std::endl;
	}
	catch (ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}
	
}
