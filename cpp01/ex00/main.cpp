/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:45:29 by nboer             #+#    #+#             */
/*   Updated: 2025/03/08 18:04:47 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *z;
	
	z = newZombie("Henk"); //heap
	z->announce();
	randomChump("Ingrid"); //stack
	delete(z);
	return (0);
}
