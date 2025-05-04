/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:57:01 by nboer             #+#    #+#             */
/*   Updated: 2025/04/26 13:38:49 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructor
WrongCat::WrongCat(){
	std::cout << "WrongCat constructed" << std::endl;
	this->_type = "WrongCat";
}

// Copy Constructor
WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal("WrongCat")
{
	*this = cpy;
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

// assignation operator overload
WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

// Deconstructor
WrongCat::~WrongCat(){
	std::cout << "WrongCat deconstructed" << std::endl;
}

// public methods
void WrongCat::makeSound() const {
	std::cout << "MMMMMMIAUW" << std::endl;
}
