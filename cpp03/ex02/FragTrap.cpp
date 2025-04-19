/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:43:54 by nboer             #+#    #+#             */
/*   Updated: 2025/04/19 16:36:18 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// constructor with name as parameter
FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->_AttackDamage = 30;
	this->_EnergyPoints = 100;
	this->_Hitpoints = 100;
	std::cout << "FragTrap " << this->_Name << " is constructed" << std::endl;
}

// copy constructor
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

// assignation operator 
FragTrap &FragTrap::operator=(const FragTrap &src){
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_Name = src._Name;
	this->_EnergyPoints = src._EnergyPoints;
	this->_Hitpoints = src._Hitpoints;
	this->_AttackDamage = src._AttackDamage;
	return *this;
}

// deconstructor
FragTrap::~FragTrap(){
	std::cout << "FragTrap " << this->_Name << " deconstructed" << std::endl;
}

// public functions
void FragTrap::attack(const std::string& target) {
	std::cout << "FragTrap " << this->_Name << " attacks " << target
			  << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "LET'S DO A HIGH FIVE GUYS" << std::endl;
}
