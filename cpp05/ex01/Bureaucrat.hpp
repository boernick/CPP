/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:13:16 by nick              #+#    #+#             */
/*   Updated: 2025/07/07 23:20:45 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string Name, int Grade);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &src);
		Bureaucrat(Bureaucrat const &b);
		
		const std::string& getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();

class GradeTooHighExeption{
	public:
}
};


#endif