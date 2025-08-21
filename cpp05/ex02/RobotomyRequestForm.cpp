/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:52:36 by nboer             #+#    #+#             */
/*   Updated: 2025/08/21 10:31:56 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

const std::string RobotomyRequestForm::_FORM_NAME = "Robotomy request form";
const int RobotomyRequestForm::_SIGN_GRADE = 72;
const int RobotomyRequestForm::_EXEC_GRADE = 45;

RobotomyRequestForm::RobotomyRequestForm() :
	AForm(_FORM_NAME, _SIGN_GRADE, _EXEC_GRADE), _target("") { }

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm(_FORM_NAME, _SIGN_GRADE, _EXEC_GRADE), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : 
	AForm(src), _target(src.getTarget()) { }
	
RobotomyRequestForm::~RobotomyRequestForm() { }

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
	if (this != &src)
		this->setSign(src.getSign());
	return *this;
}

std::string RobotomyRequestForm::getTarget() const {
	return _target;
	
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	int random_n;
	
	if (!getSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExGrade())
		throw AForm::GradeTooLowException();
	std::cout << "*drilling noises*" << std::endl;
	random_n = rand() % 2;
	if (random_n == 0)
		std::cout << this->getTarget() << " has been robotomized succesfully." << std::endl;
	else
		std::cout << this->getTarget() << " has failed the robotomization" << std::endl;
}
