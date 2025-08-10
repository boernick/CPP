/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:52:34 by nboer             #+#    #+#             */
/*   Updated: 2025/08/10 17:57:55 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_h
#define RobotomyRequestForm_h

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	private:
		const std::string _target;
		
		static const std::string _FORM_NAME;
		static const int _SIGN_GRADE;
		static const int _EXEC_GRADE;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};

#endif
