/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:41:42 by nboer             #+#    #+#             */
/*   Updated: 2025/05/04 18:19:12 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// constructor
Animal::Animal(){
	std::cout << "Animal constructed" << std::endl;
	this->_type = "Generic Animal";
}

// copy contructor
Animal::Animal(const Animal &src){
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = src._type;
}

// assignation operator
Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

// deconstructor
Animal::~Animal(){
	std::cout << "Animal deconstructed" << std::endl;
}

// public methods
void Animal::makeSound() const {
	std::cout << "*Random screaming*" << std::endl;
}

std::string Animal::getType() const{
	return this->_type;
}
