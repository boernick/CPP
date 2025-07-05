/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:54:35 by nboer             #+#    #+#             */
/*   Updated: 2025/07/05 16:46:33 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain *_brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog &cpy);
		Dog &operator=(const Dog &src);
		void makeSound() const;
		Brain* getBrain() const;
};

#endif
