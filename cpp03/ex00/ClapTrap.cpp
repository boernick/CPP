/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:19:04 by nick              #+#    #+#             */
/*   Updated: 2025/04/17 17:25:41 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name)
{
	this->_Name = Name;
	this->_AttackDamage = 0;
	this->_EnergyPoints = 10;
	this->_Hitpoints = 10;
	std::cout << "ClapTrap " << Name << " is created" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->_Name << " has been deconstructed" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_Hitpoints + amount <= 10)
	{
		this->_Hitpoints += amount;
		this->_EnergyPoints --;
		std::cout << "ClapTrap " << this->_Name << " heals itself to " << this->_Hitpoints << " hp" << std::endl;
	}
	else if (this->_EnergyPoints <= 0 || this-> _Hitpoints <= 0)
		std::cout << this->_Name << " is too weak to beRepaired" << std::endl;
	else
		std::cout << "ClapTrap " << this->_Name << " cannot heal that much" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	this->_Hitpoints -= amount;
	std::cout << this->_Name << " takes " << amount << " damage. " << this->_Hitpoints << " left" << std::endl;
	
}

void ClapTrap::attack(const std::string& target){
	if (this->_EnergyPoints <= 0 || this->_Hitpoints <= 0)
		std::cout << this->_Name << " is too weak to attack!" << std::endl;
	else
		std::cout << "ClapTrap " << this->_Name << " attacks " << target
			<< ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	this->_EnergyPoints--;
}
