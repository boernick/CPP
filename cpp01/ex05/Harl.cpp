/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:31:21 by nboer             #+#    #+#             */
/*   Updated: 2025/03/15 19:04:26 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
	_level[0] = "DEBUG";
	_level[1] = "INFO";
	_level[2] = "WARNING";
	_level[3] = "ERROR";
}

void Harl::debug(void){
	std::cout << DEBUG << std::endl;
}

void Harl::info(void){
	std::cout << INFO << std::endl;
}

void Harl::warning(void){
	std::cout << WARNING << std::endl;
}

void Harl::error(void){
	std::cout << ERROR << std::endl;
}

void Harl::complain(std::string level){
	
	void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, 
			&Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (_level[i] == level)
			(this->*functions[i])();
	}
}

std::string Harl::getLevel(int index)
{
	return (_level[index]);
}
