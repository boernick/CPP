/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:45:48 by nboer             #+#    #+#             */
/*   Updated: 2025/03/09 18:54:43 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(void){}

Zombie::Zombie(std::string _name){
	setName(_name);
	std::cout << name << " spawned" << std::endl;	
}

Zombie::~Zombie(void){
	std::cout << name << " died" << std::endl;
}

void Zombie::setName(std::string _name){
	name = _name;
}

void	Zombie::announce(void){
	std::cout << name << ": " << ZOMBIE_MSG << std::endl;	
}
