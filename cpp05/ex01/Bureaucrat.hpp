/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:13:16 by nick              #+#    #+#             */
/*   Updated: 2025/07/08 22:58:42 by nick             ###   ########.fr       */
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
			
		}
	
		Bureaucrat();
		Bureaucrat(Bureaucrat& const ref);
		Bureaucrat(std::string Name, int Grade);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &src);
		Bureaucrat(Bureaucrat const &b);
		
		const std::string& getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();

};


#endif