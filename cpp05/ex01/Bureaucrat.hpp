/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:13:16 by nick              #+#    #+#             */
/*   Updated: 2025/07/07 23:14:34 by nick             ###   ########.fr       */
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
		Bureaucrat(std::string Name, int Grade);
		~Bureaucrat();
		const std::string& getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
		void checkBounds(int Grade);

class GradeTooHighExeption{
	public:
}
};


#endif