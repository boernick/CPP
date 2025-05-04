/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:41:42 by nboer             #+#    #+#             */
/*   Updated: 2025/05/04 16:17:11 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// constructor
WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal constructed" << std::endl;
	this->_type = "Generic WrongAnimal";
}

// constructor with type parameter
WrongAnimal::WrongAnimal(std::string type){
	std::cout << "WrongAnimal constructed of type: " << this->_type << std::endl;
	this->_type = type;
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
	this->_type = src._type;
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
	return this->_type;
}
