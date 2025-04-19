/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:57:01 by nboer             #+#    #+#             */
/*   Updated: 2025/04/19 17:23:47 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor
Cat::Cat(){
	std::cout << "Cat constructed" << std::endl;
	this->_Type = "Cat";
}

// Deconstructor
Cat::~Cat(){
	std::cout << "Cat deconstructed" << std::endl;
}

// public methods
void Cat::makeSound(){
	std::cout << "MMMMMMIAUW" << std::endl;
}
