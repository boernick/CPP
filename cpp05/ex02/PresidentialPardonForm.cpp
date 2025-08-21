/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:45:51 by nboer             #+#    #+#             */
/*   Updated: 2025/08/21 10:26:52 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

const std::string PresidentialPardonForm::_FORM_NAME= "Presidential Pardon Form";
const int PresidentialPardonForm::_SIGN_GRADE = 25;
const int PresidentialPardonForm::_EXEC_GRADE = 5;

PresidentialPardonForm::PresidentialPardonForm() :
	AForm(_FORM_NAME, _SIGN_GRADE, _EXEC_GRADE), _target("") { }

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm(_FORM_NAME, _SIGN_GRADE, _EXEC_GRADE), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : 
	AForm(src), _target(src.getTarget()) { }
	
PresidentialPardonForm::~PresidentialPardonForm() { }

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {
	if (this != &src)
		this->setSign(src.getSign());
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
	return _target;
	
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
