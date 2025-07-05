/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:54:35 by nboer             #+#    #+#             */
/*   Updated: 2025/07/05 16:42:46 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Brain;

class Cat : public AAnimal{
	private:
		Brain *_brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		void makeSound() const;
		Brain* getBrain() const;
};

#endif
