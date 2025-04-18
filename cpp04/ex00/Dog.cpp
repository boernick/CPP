/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:55:11 by nboer             #+#    #+#             */
/*   Updated: 2025/04/19 18:07:35 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:41:42 by nboer             #+#    #+#             */
/*   Updated: 2025/04/19 16:51:47 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// constructor
Dog::Dog() : Animal(){
	std::cout << "Dog constructed" << std::endl;
	this->_Type = "Dog";
}

// copy constructor
Dog::Dog(const Dog &cpy) : Animal("Dog"){
	*this = cpy;
	std::cout << "Dog copy constructor called" << std::endl;
}

// assignation operator overload
Dog &Dog::operator=(const Dog &src){
	std::cout << "Dog Assignation operator called" << std::endl;
	this->_Type = src._Type;
	return *this;
}

// deconstructor
Dog::~Dog(){
	std::cout << "Dog deconstructed" << std::endl;
}

// public methods
void Dog::makeSound(){
	std::cout << "BARKY BARK BARK" << std::endl;
}


