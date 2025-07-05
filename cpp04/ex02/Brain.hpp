/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:19:59 by nboer             #+#    #+#             */
/*   Updated: 2025/07/05 16:26:50 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain (const Brain &cpy);
		Brain &operator=(const Brain &src);
		~Brain();
		std::string getIdea(int i) const;
		void setIdea(int i, std::string str);
};

#endif
