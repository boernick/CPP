/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:45:51 by nboer             #+#    #+#             */
/*   Updated: 2025/08/10 16:39:28 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_H
#define PresidentialPardonForm_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		const std::string _target;
		
		static const std::string _FORM_NAME;
		static const int _SIGN_GRADE;
		static const int _EXEC_GRADE;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};

#endif
