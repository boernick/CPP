/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:29:33 by nick              #+#    #+#             */
/*   Updated: 2025/04/19 15:30:33 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{	
	FragTrap hans("Hans");
	ClapTrap sjoerd("Sjoerd");
	ScavTrap nick("Nick");

	hans.attack("a random target");
	sjoerd.attack("a small target");
	nick.attack("a big target");
	sjoerd.takeDamage(5);
	nick.takeDamage(5);
	hans.takeDamage(5);
	nick.guardGate();
	hans.highFivesGuys();
	return (0);	
}
