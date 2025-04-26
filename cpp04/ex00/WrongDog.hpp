/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:54:35 by nboer             #+#    #+#             */
/*   Updated: 2025/04/26 14:18:42 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_H
#define WRONGDOG_H

#include <iostream>
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
	public:
		WrongDog();
		~WrongDog();
		WrongDog(const WrongDog &cpy);
		WrongDog &operator=(const WrongDog &src);
		void makeSound() const;
};

#endif
