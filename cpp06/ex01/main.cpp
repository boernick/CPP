/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:37:55 by nboer             #+#    #+#             */
/*   Updated: 2025/08/28 18:01:14 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data data;
	Data *p;
	uintptr_t uip;

	data.key = "a secret";
	data.value = "message";
	std::cout << data.key << " " << data.value << std::endl;

	p = &data;
	uip = Serializer::serialize(p);
	std::cout << uip << std::endl;
	
	p = Serializer::deserialize(uip);
	std::cout << data.key << " " << data.value << std::endl;
}
