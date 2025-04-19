/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:42:03 by nboer             #+#    #+#             */
/*   Updated: 2025/04/19 17:57:37 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal{
	protected:
		std::string _Type;
	public:
		Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &src);
		Animal(std::string type);
		~Animal();
		
};

#endif
