/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:15:36 by nick              #+#    #+#             */
/*   Updated: 2025/07/08 20:09:47 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
	std::cout << "constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string Name, const int Grade) throw(GradeTooLowException, GradeTooHighExeption){ }

Bureaucrat::Bureaucrat(Bureaucrat& const ref) : _name(ref._name), _grade(ref._grade) {
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
	_grade -= 1;
}

void Bureaucrat::decGrade(){
	_grade += 1;
}
