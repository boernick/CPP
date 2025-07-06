/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:13:16 by nick              #+#    #+#             */
/*   Updated: 2025/07/06 19:40:00 by nick             ###   ########.fr       */
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
		Bureaucrat(std::string Name);
		~Bureaucrat();
		const std::string& getName() const;
		int getGrade() const;
};


#endif