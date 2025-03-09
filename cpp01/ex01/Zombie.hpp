/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:49:33 by nboer             #+#    #+#             */
/*   Updated: 2025/03/09 19:07:02 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <iomanip>

# define ZOMBIE_MSG "BraiiiiiiinnnzzzZ..."

class Zombie{
	private:
		std::string	name;
	
	public:
		Zombie();
		Zombie(std::string _name);
		~Zombie(void);
		void announce(void);
		void setName(std::string _name);
};

Zombie	*newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);

# endif
