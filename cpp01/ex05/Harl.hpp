/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:31:28 by nboer             #+#    #+#             */
/*   Updated: 2025/03/15 18:48:11 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>

#define DEBUG "I love extra bacon on 7XL-double-specialketchup burger"
#define INFO "I cannot believe adding extra bacon costs more money."
#define WARNING "I think I deserve to have some extra bacon for free."
#define ERROR "This is unacceptable! I want to speak to the manager now."

class Harl {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	std::string _level[4];
public:
	Harl();
	void complain(std::string level);
	std::string getLevel(int index);
};

#endif

