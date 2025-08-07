/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:18:51 by nboer             #+#    #+#             */
/*   Updated: 2025/08/07 14:45:10 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _sign(false), _sign_grade(1), _exec_grade(1) {
	std::cout << "constructor called" << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exec_grade) :
	_name(name),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade),
	_sign(false) {
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();	
}

Form::Form(Form const &ref) : _name(ref._name), _sign(ref._sign), 
	_sign_grade(ref._sign_grade),_exec_grade(ref._exec_grade) {
	std::cout << "copy constructor called" << std::endl;
}

Form::~Form(){
	std::cout << "form deconstructor called" << std::endl;
}

Form &Form::operator=(Form const &src){
	if (this != &src)
		this->_sign = src._sign;
	return *this;
}

const std::string& Form::getName() const {
	return this->_name;
}

const int Form::getSignGrade() const {
	return this->_sign_grade;
}

const int Form::getExGrade() const {
	return this->_exec_grade;
}

bool Form::getSign() const {
	return this->_sign;
}

void Form::beSigned(Bureaucrat const &b) {
	if (b.getGrade() > _sign_grade)
		throw GradeTooLowException();
	else
		_sign = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}


