/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:18:54 by nboer             #+#    #+#             */
/*   Updated: 2025/08/09 11:54:33 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>

class Bureaucrat;

class Form{
	private:
		const std::string _name;
		bool _sign;
		const int _sign_grade;
		const int _exec_grade;
	public:
		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		
		Form();
		Form(Form const &f);
		Form(std::string name, const int sign_grade, const int exec_grade);
		~Form();
		Form &operator=(Form const &src);
		const std::string& getName() const;
		int getSignGrade() const;
		int getExGrade() const;
		bool getSign() const;
		void beSigned(Bureaucrat const &b);		
};

std::ostream& operator<<(std::ostream &out, const Form &f);

#endif
