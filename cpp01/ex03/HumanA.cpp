/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:05:27 by nboer             #+#    #+#             */
/*   Updated: 2025/03/13 16:07:22 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon){
	this->_name = name;
	this->_weapon = &weapon;
}

void HumanA::attack(){
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
