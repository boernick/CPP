/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:18:51 by nboer             #+#    #+#             */
/*   Updated: 2025/08/09 11:56:54 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(""), _sign(false), _sign_grade(1), _exec_grade(1) {
	std::cout << "constructor called" << std::endl;
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade) :
	_name(name),
	_sign(false),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade) {
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();	
}

AForm::AForm(AForm const &ref) : _name(ref._name), _sign(ref._sign), 
	_sign_grade(ref._sign_grade),_exec_grade(ref._exec_grade) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(){
	std::cout << "AForm deconstructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &src){
	if (this != &src)
		this->_sign = src._sign;
	return *this;
}

const std::string& AForm::getName() const {
	return this->_name;
}

int AForm::getSignGrade() const {
	return this->_sign_grade;
}

int AForm::getExGrade() const {
	return this->_exec_grade;
}

bool AForm::getSign() const {
	return this->_sign;
}

void AForm::beSigned(Bureaucrat const &b) {
	if (b.getGrade() > _sign_grade)
		throw GradeTooLowException();
	else
		_sign = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream& os, const AForm& f) {
	os << f.getName() << ", exec grade " << f.getExGrade()  << ", sign grade " 
		<< f.getSignGrade() << ", signed " << (f.getSign()?"yes":"no");
	return os;
}
