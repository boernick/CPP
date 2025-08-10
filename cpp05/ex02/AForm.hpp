/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:18:54 by nboer             #+#    #+#             */
/*   Updated: 2025/08/09 11:54:33 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_H
#define AForm_H

#include <iostream>

class Bureaucrat;

class AForm{
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
		class FormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		
		AForm();
		AForm(AForm const &f);
		AForm(std::string name, const int sign_grade, const int exec_grade);
		~AForm();
		AForm &operator=(AForm const &src);
		const std::string& getName() const;
		int getSignGrade() const;
		int getExGrade() const;
		bool getSign() const;
		void beSigned(Bureaucrat const &b);
		virtual void execute(Bureaucrat const & executor) const = 0;
	protected:
		void setSign(bool value);
};

std::ostream& operator<<(std::ostream &out, const AForm &f);

#endif
