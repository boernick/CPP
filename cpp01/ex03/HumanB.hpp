/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:28:32 by nboer             #+#    #+#             */
/*   Updated: 2025/03/13 13:18:37 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB{
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		HumanB();
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack();
};

#endif
