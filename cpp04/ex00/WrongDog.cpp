/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:55:11 by nboer             #+#    #+#             */
/*   Updated: 2025/04/26 14:17:59 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

// constructor
WrongDog::WrongDog() : WrongAnimal(){
	std::cout << "WrongDog constructed" << std::endl;
	this->_Type = "WrongDog";
}

// copy constructor
WrongDog::WrongDog(const WrongDog &cpy) : WrongAnimal("WrongDog"){
	*this = cpy;
	std::cout << "WrongDog copy constructor called" << std::endl;
}

// assignation operator overload
WrongDog &WrongDog::operator=(const WrongDog &src){
	std::cout << "WrongDog Assignation operator called" << std::endl;
	this->_Type = src._Type;
	return *this;
}

// deconstructor
WrongDog::~WrongDog(){
	std::cout << "WrongDog deconstructed" << std::endl;
}

// public methods
void WrongDog::makeSound() const{
	std::cout << "BARKY BARK BARK" << std::endl;
}


