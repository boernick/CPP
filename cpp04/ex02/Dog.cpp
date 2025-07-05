/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:55:11 by nboer             #+#    #+#             */
/*   Updated: 2025/07/05 16:46:21 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// constructor
Dog::Dog() : AAnimal(){
	std::cout << "Dog constructed" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

// copy constructor
Dog::Dog(const Dog &src) : AAnimal(src){
	this->_brain = new Brain(*src._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

// assignation operator overload
Dog &Dog::operator=(const Dog &src){
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return *this;
}

// deconstructor
Dog::~Dog(){
	delete _brain;
	std::cout << "Dog deconstructed" << std::endl;
}

// public methods
void Dog::makeSound() const{
	std::cout << "BARKY BARK BARK" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}


