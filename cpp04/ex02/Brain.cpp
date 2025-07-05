/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:19:45 by nboer             #+#    #+#             */
/*   Updated: 2025/05/04 17:07:41 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructed" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
}

Brain::Brain(const Brain &cpy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = cpy._ideas[i];
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignation operator called";
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}	
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain deconstructed" << std::endl;
}

//public functions
std::string Brain::getIdea(int i) const {
	return (_ideas[i]);
}

void Brain::setIdea(int i, std::string str)
{
	_ideas[i] = str;
}

