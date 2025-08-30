/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:56:11 by nboer             #+#    #+#             */
/*   Updated: 2025/08/30 18:13:09 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template<typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}

int main(void) {
	std::string	str_array[] = {"This", "is", "a", "string", "array"};
	int			int_array[] = {1, 2, 3, 4, 5};
	int			empty_array[] = {};

	iter(str_array, 5, &print<std::string>);
	iter(int_array, 5, &print<int>);
	iter(empty_array, 0, &print<int>);
	return (0);
}
