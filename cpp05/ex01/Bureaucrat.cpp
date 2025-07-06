/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:15:36 by nick              #+#    #+#             */
/*   Updated: 2025/07/06 19:45:33 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string Name) : name(Name){
	std::cout << "constructor called for " << this->name << std::endl;
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