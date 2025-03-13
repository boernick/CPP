/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:55:00 by nboer             #+#    #+#             */
/*   Updated: 2025/03/13 13:29:30 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <iomanip>
# include <string.h>

class Weapon{
	private:
		std::string _type;
	public:
		Weapon();
		Weapon(std::string type);
		void setType(std::string type);
		const std::string getType();
};

#endif
