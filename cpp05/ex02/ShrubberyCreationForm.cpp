/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:45:51 by nboer             #+#    #+#             */
/*   Updated: 2025/08/10 18:06:11 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_FORM_NAME = "Robotomy request form";
const int ShrubberyCreationForm::_SIGN_GRADE = 145;
const int ShrubberyCreationForm::_EXEC_GRADE = 137;

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm(_FORM_NAME, _SIGN_GRADE, _EXEC_GRADE), _target("") { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm(_FORM_NAME, _SIGN_GRADE, _EXEC_GRADE), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : 
	AForm(src), _target(src.getTarget()) { }
	
ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
	if (this != &src)
		this->setSign(src.getSign());
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
	
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::ofstream outfile;
	std::string filename;
	
	if (!getSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExGrade())
		throw AForm::GradeTooLowException();

	filename = _target + "_shrubbery";
	outfile.open(filename.c_str());
	if (outfile.fail())
		std::cout << "error while opening outfile." << std::endl;
	else
		outfile << "    /\\    \n";
		outfile << "   /  \\   \n";
		outfile << "  /    \\  \n";
		outfile << " /      \\ \n";
		outfile << "/________\\\n";
		outfile << "    ||    \n";
		outfile << "    ||    \n";
		outfile << "    ||    \n";
		outfile.close();
	}
