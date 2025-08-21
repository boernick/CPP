/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:15:36 by nick              #+#    #+#             */
/*   Updated: 2025/08/21 10:32:51 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string Name, const int Grade) : _name(Name), _grade(Grade){ 
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();	
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) : _name(ref._name), _grade(ref._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat deconstructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::signForm(AForm &f) const {
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << "." << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << _name << " couldn't sign " << f.getName() 
			<< " because their grade is too low." << std::endl;
	}
}

void Bureaucrat::incGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade -= 1;
	
}

void Bureaucrat::decGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade += 1;
}

void Bureaucrat::executeForm(AForm const &form){
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << _name << " was unable to execute " << form.getName()
		<< "because the grade is too low." << std::endl;
	}
	catch (AForm::FormNotSignedException &e) {
		std::cout << _name << " was unable to execute " << form.getName()
		<< "because the form is not signed." << std::endl;
	}
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade(); 
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}
