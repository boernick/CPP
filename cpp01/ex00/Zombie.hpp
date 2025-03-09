/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:49:33 by nboer             #+#    #+#             */
/*   Updated: 2025/03/08 17:29:22 by nboer            ###   ########.fr       */
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
		Zombie(std::string _name);
		~Zombie(void);
		void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

# endif
