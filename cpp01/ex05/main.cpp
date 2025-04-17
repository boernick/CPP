/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:33:01 by nboer             #+#    #+#             */
/*   Updated: 2025/03/16 15:56:24 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	Karen;
	int		n_complaints = 20;

	for (int i = 0; i < n_complaints; i++)
		Karen.complain(Karen.getLevel(i % 4));
	return (0);
}
