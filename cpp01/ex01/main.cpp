/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:45:29 by nboer             #+#    #+#             */
/*   Updated: 2025/03/09 19:09:54 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde;
	int size = 5;
		
	horde = zombieHorde(size, "UNDEAD");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
