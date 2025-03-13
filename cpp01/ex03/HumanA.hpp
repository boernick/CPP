/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:28:32 by nboer             #+#    #+#             */
/*   Updated: 2025/03/13 13:23:29 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

class HumanA{
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		HumanA();
		HumanA(std::string name, Weapon &weapon);
		void attack();
};

#endif
