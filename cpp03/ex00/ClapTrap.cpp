/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:19:04 by nick              #+#    #+#             */
/*   Updated: 2025/04/18 17:22:26 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// constructor with name parameter
ClapTrap::ClapTrap(std::string Name): _Name(Name), _AttackDamage(0), _EnergyPoints(10), _Hitpoints(10){
	std::cout << "ClapTrap " << Name << " is created" << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

// assignation operator 
ClapTrap &ClapTrap::operator=(const ClapTrap &src){
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->_Name = src._Name;
	this->_EnergyPoints = src._EnergyPoints;
	this->_Hitpoints = src._Hitpoints;
	this->_AttackDamage = src._AttackDamage;
	return *this;
}

// deconstructor
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->_Name << " has been deconstructed" << std::endl;
}

// public functions
void ClapTrap::beRepaired(unsigned int amount){
	if (this->_EnergyPoints <= 0 || this-> _Hitpoints <= 0)
		std::cout << this->_Name << " is too weak to beRepaired" << std::endl;
	else if (this->_Hitpoints + amount > 10)
		std::cout << "ClapTrap " << this->_Name << " cannot heal that much" << std::endl;
	else
	{
		this->_Hitpoints += amount;
		this->_EnergyPoints --;
		std::cout << "ClapTrap " << this->_Name << " heals itself to " << this->_Hitpoints << " hp" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_Hitpoints <= 0)
		std::cout << "ClapTrap " << this->_Name << " is KIA and has no more HP" << std::endl;
	else
	{
		this->_Hitpoints -= amount;
		std::cout << this->_Name << " takes " << amount << " damage. " << this->_Hitpoints << " left" << std::endl;
	}
}

void ClapTrap::attack(const std::string& target){
	if (this->_EnergyPoints <= 0 || this->_Hitpoints <= 0)
		std::cout << this->_Name << " is too weak to attack!" << std::endl;
	else
		std::cout << "ClapTrap " << this->_Name << " attacks " << target
			<< ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	this->_EnergyPoints--;
}
