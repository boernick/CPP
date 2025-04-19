/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:29:33 by nick              #+#    #+#             */
/*   Updated: 2025/04/19 15:45:57 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{	
	ClapTrap sjoerd("sjoerd");
	ScavTrap nick("nick");

	sjoerd.attack("target");
	nick.attack("target");
	sjoerd.takeDamage(5);
	nick.takeDamage(5);
	nick.guardGate();
	return (0);	
}
