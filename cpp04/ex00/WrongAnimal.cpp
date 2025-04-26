/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:41:42 by nboer             #+#    #+#             */
/*   Updated: 2025/04/26 14:23:18 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// constructor
WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal constructed" << std::endl;
	this->_Type = "Generic WrongAnimal";
}

// constructor with type parameter
WrongAnimal::WrongAnimal(std::string type){
	std::cout << "WrongAnimal constructed of type: " << this->_Type << std::endl;
	this->_Type = type;
}

// copy contructor
WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

// assignation operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_Type = src._Type;
	return *this;
}

// deconstructor
WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal deconstructed" << std::endl;
}

// public methods
void WrongAnimal::makeSound() const {
	std::cout << "*Random screaming*" << std::endl;
}

std::string WrongAnimal::getType() const{
	return this->_Type;
}
