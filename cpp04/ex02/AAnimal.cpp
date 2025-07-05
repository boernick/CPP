/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:41:42 by nboer             #+#    #+#             */
/*   Updated: 2025/07/05 16:56:11 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// deconstructor
AAnimal::~AAnimal(){
	std::cout << "Animal deconstructed" << std::endl;
}

std::string AAnimal::getType() const{
	return this->_type;
}
