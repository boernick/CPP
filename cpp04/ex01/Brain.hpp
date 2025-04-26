/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:19:59 by nboer             #+#    #+#             */
/*   Updated: 2025/04/26 15:41:06 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

struct Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain (const Brain &cpy);
		Brain &operator=(const Brain &src);
		~Brain();
};

#endif
