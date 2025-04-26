/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:54:35 by nboer             #+#    #+#             */
/*   Updated: 2025/04/26 16:20:05 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Brain;

class Cat : public Animal{
	private:
		Brain *_Brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat &cpy);
		Cat &operator=(const Cat &src);
		void makeSound() const;
};

#endif
