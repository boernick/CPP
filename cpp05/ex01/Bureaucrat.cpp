/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:15:36 by nick              #+#    #+#             */
/*   Updated: 2025/07/11 21:45:33 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
	std::cout << "constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string Name, const int Grade) throw(GradeTooLowException, GradeTooHighExeption) : _name(Name), _grade(Grade){
	if (_grade < 1)
		throw GradeTooHighExeption();
	if (_grade > 150)
		throw GradeTooLowException();	
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) : _name(ref._name), _grade(ref._grade) {
	std::cout << "copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "deconstructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const{
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incGrade(){
	if (_grade == 1)
		throw GradeTooHighExeption();
	_grade -= 1;
	
}

void Bureaucrat::decGrade(){
	if (_grade == 150)
		throw GradeTooLowException();
	_grade += 1;
}
