/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:45:51 by nboer             #+#    #+#             */
/*   Updated: 2025/08/21 16:05:03 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_h
#define ShrubberyCreationForm_h

#include <cstdlib>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	private:
		const std::string _target;
		
		static const std::string _FORM_NAME;
		static const int _SIGN_GRADE;
		static const int _EXEC_GRADE;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
		static AForm *create(std::string target);
};

#endif
