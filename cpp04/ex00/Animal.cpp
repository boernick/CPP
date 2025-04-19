/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:41:42 by nboer             #+#    #+#             */
/*   Updated: 2025/04/19 17:38:58 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// constructor
Animal::Animal(){
	std::cout << "Animal constructed" << std::endl;
	this->_Type = "Generic Animal";
}

// constructor with type parameter
Animal::Animal(std::string type){
	this->_Type = type;
	std::cout << "Animal constructed of type: " << this->_Type << std::endl;
}

// copy contructor
Animal::Animal(const Animal &copy){
	
}

// deconstructor
Animal::~Animal(){
	std::cout << "Animal deconstructed" << std::endl;
}
