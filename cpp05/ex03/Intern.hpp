/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:20:17 by nboer             #+#    #+#             */
/*   Updated: 2025/08/21 15:43:34 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include <string>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern{
	private:
		AForm*	(*_form_class[3])(std::string);
	public:
		Intern();
		~Intern();
		Intern(Intern const &i);
		Intern &operator=(Intern const &src);
		
		AForm *MakeForm(std::string form_name, std::string form_target);
};

#endif
