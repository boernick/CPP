/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:42:00 by nboer             #+#    #+#             */
/*   Updated: 2025/08/28 15:48:54 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCALAR_CONVERTER_H
#define _SCALAR_CONVERTER_H

#include <iostream>
#include <cstdlib>
#include <limits>
#include <stdexcept>

class ScalarConverter{
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		class ConversionFailedException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		static void convert(std::string str);
};

#endif
