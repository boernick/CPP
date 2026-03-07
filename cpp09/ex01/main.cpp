/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:33:54 by nick              #+#    #+#             */
/*   Updated: 2025/11/08 14:34:06 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Error: wrong argument count." << std::endl;
	else
	{
		RPN rpn;
		rpn.calculate(av[1]);
	}
	return 0;
}