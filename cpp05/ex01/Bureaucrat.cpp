/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:15:36 by nick              #+#    #+#             */
/*   Updated: 2025/07/07 23:21:13 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string Name, int Grade) : name(Name), grade(Grade) {
	std::cout << "constructor called for " << this->name << std::endl;
	checkBounds(grade);
}

void Bureaucrat::checkBounds(int Grade){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
	std::cout << "deconstructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const{
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incGrade(){
	grade -= 1;
	checkBounds(grade);
}

void Bureaucrat::decGrade(){
	grade += 1;
	checkBounds(grade);
}
