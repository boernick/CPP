/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:56:15 by nick              #+#    #+#             */
/*   Updated: 2025/04/19 15:45:26 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructor with name as parameter
ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "Scavtrap " << name << " constructed" << std::endl;
	this->_AttackDamage = 20;
	this->_EnergyPoints = 50;
	this->_Hitpoints = 100;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

// deconstructor
ScavTrap::~ScavTrap() {
	std::cout << "Scavtrap " << this->_Name << " deconstructed" << std::endl;
}

// assignation operator 
ScavTrap &ScavTrap::operator=(const ScavTrap &src){
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_Name = src._Name;
	this->_EnergyPoints = src._EnergyPoints;
	this->_Hitpoints = src._Hitpoints;
	this->_AttackDamage = src._AttackDamage;
	return *this;
}

// public functions
void ScavTrap::attack(const std::string& target) {
	std::cout << "Scavtrap " << this->_Name << " attacks " << target
			  << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "Scavtrap " << this->_Name << " is now in Gate Keeper Mode" << std::endl;
}

