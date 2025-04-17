/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:06:33 by nboer             #+#    #+#             */
/*   Updated: 2025/03/11 22:49:10 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie *horde = new Zombie[N];
	
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}
