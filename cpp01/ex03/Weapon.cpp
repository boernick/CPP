/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:55:19 by nboer             #+#    #+#             */
/*   Updated: 2025/03/13 13:29:56 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

void Weapon::setType(std::string type){
	this->_type = type;
}

const std::string Weapon::getType(){
	return (this->_type);
}
