/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:13:16 by nick              #+#    #+#             */
/*   Updated: 2025/08/03 17:47:09 by nboer            ###   ########.fr       */
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
		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
	
		Bureaucrat();
		Bureaucrat(Bureaucrat const &b);
		Bureaucrat(std::string Name, int Grade) throw(GradeTooHighException, GradeTooLowException);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &src);
		const std::string& getName() const;
		int getGrade() const;
		void incGrade() throw(GradeTooHighException);
		void decGrade() throw(GradeTooLowException);
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif
