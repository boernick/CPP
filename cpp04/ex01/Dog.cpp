/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:55:11 by nboer             #+#    #+#             */
/*   Updated: 2025/05/04 16:21:26 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// constructor
Dog::Dog() : Animal(){
	std::cout << "Dog constructed" << std::endl;
	this->_type = "Dog";
	this->_Brain = new Brain;
}

// copy constructor
Dog::Dog(const Dog &cpy) : Animal("Dog"){
	*this = cpy;
	std::cout << "Dog copy constructor called" << std::endl;
}

// assignation operator overload
Dog &Dog::operator=(const Dog &src){
	std::cout << "Dog Assignation operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

// deconstructor
Dog::~Dog(){
	delete this->_Brain;
	std::cout << "Dog deconstructed" << std::endl;
}

// public methods
void Dog::makeSound() const{
	std::cout << "BARKY BARK BARK" << std::endl;
}


