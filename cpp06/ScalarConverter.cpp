/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:42:02 by nboer             #+#    #+#             */
/*   Updated: 2025/08/23 18:52:15 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


bool isChar(std::string const str){
	if (str.length() != 3 && str[1] != 
}

bool isInt(std::string const str){
	size_t	i = 0;
	
	if (str[0] == '+' || str[0] == '-')
		i++;
	for (; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return (i > (str[0] == '+' || str[0] == '-'));
}

bool isDouble(std::string const str){
	size_t	i = 0;
	int	dot = 0;
	int digits = 0;
	
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return true;
	if (str[0] == '+' || str[0] == '-')
		i++;
	for (; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			digits++;
		else if (str[i] == '.' && !dot)
			dot = 1;
		else
			return false;
	}
	return (digits > 0 && dot == 1);
}

bool isFloat(std::string const str){
	std::string substr;
	size_t len;

	len = str.length();
	if (str[len - 1] != 'f' || len < 2)
		return false;
	substr = str.substr(0, len - 1);
	return (isDouble(substr) || isInt(substr));
}




