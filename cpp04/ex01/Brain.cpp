/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:19:45 by nboer             #+#    #+#             */
/*   Updated: 2025/04/26 15:57:58 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	*this = cpy;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignation operator called";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain deconstructed" << std::endl;
}
