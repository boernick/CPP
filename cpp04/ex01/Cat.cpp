/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:57:01 by nboer             #+#    #+#             */
/*   Updated: 2025/05/04 18:37:35 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

// Constructor
Cat::Cat(){
	std::cout << "Cat constructed" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

// Copy Constructor
Cat::Cat(const Cat &src) : Animal(src){
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
}

// assignation operator overload
Cat &Cat::operator=(const Cat &src) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*src._brain); // Deep copy again
	}
	return *this;
}

// Deconstructor
Cat::~Cat(){
	std::cout << "Cat deconstructed" << std::endl;
	delete _brain;
}

// public methods
void Cat::makeSound() const {
	std::cout << "MMMMMMIAUW" << std::endl;
}

Brain* Cat::getBrain() const{
	return this->_brain;
}
