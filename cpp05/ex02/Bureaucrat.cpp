/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:15:36 by nick              #+#    #+#             */
/*   Updated: 2025/08/07 15:14:33 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
	std::cout << "constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string Name, const int Grade) throw(GradeTooLowException, GradeTooHighException) : _name(Name), _grade(Grade){
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();	
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) : _name(ref._name), _grade(ref._grade) {
	std::cout << "copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "deconstructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

const std::string& Bureaucrat::getName() const{
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::signForm(Form &f) const {
	
}


void Bureaucrat::incGrade() throw(GradeTooHighException){
	if (_grade == 1)
		throw GradeTooHighException();
	_grade -= 1;
	
}

void Bureaucrat::decGrade() throw(GradeTooLowException){
	if (_grade == 150)
		throw GradeTooLowException();
	_grade += 1;
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
