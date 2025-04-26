/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:57:01 by nboer             #+#    #+#             */
/*   Updated: 2025/04/26 16:46:05 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

// Constructor
Cat::Cat(){
	std::cout << "Cat constructed" << std::endl;
	this->_Type = "Cat";
	this->_Brain = new Brain;
}

// Copy Constructor
Cat::Cat(const Cat &cpy) : Animal("Cat")
{
	*this = cpy;
	std::cout << "Cat Copy Constructor called" << std::endl;
}

// assignation operator overload
Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_Type = src._Type;
		if (this->_Brain)
			delete this->_Brain;
		this->_Brain = new Brain();
	}
}

// Deconstructor
Cat::~Cat(){
	delete this->_Brain;
	std::cout << "Cat deconstructed" << std::endl;
}

// public methods
void Cat::makeSound() const {
	std::cout << "MMMMMMIAUW" << std::endl;
}
