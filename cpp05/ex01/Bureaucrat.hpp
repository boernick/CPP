/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:13:16 by nick              #+#    #+#             */
/*   Updated: 2025/07/11 21:28:24 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
	public:
		class GradeTooHighExeption : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
	
		Bureaucrat();
		Bureaucrat(Bureaucrat const &ref);
		Bureaucrat(std::string Name, int Grade) throw(GradeTooHighExeption, GradetooLowException);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &src);
		Bureaucrat(Bureaucrat const &b);
		
		const std::string& getName() const;
		int getGrade() const;
		void incGrade() throw(GradeTooHighException);
		void decGrade() throw(GradeTooLowException);

};


#endif