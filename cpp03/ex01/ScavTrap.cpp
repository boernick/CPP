/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:56:15 by nick              #+#    #+#             */
/*   Updated: 2025/04/18 20:43:25 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "Scavtrap " << name << " constructed" << std::endl;
	this->_AttackDamage = 20;
	this->_EnergyPoints = 50;
	this->_Hitpoints = 100;
}

ScavTrap::~ScavTrap() {
	std::cout << "Scavtrap " << this->_Name << " destructed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	std::cout << "Scavtrap " << this->_Name << " attacks " << target
			  << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "Scavtrap " << this->_Name << "is now in Gate Keeper Mode" << std::endl;
}

