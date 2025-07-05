/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:42:03 by nboer             #+#    #+#             */
/*   Updated: 2025/07/05 16:55:34 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>

class AAnimal{
	protected:
		std::string _type;
	public:
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif
