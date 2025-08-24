/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:42:02 by nboer             #+#    #+#             */
/*   Updated: 2025/08/24 17:42:38 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isChar(std::string const str){
	return (str.length() == 1 && isprint(str[0]));
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

ScalarTypes *readTypeChar(std::string str) {
	ScalarTypes *types;
	
	types = new ScalarTypes;
	types->setChar(str[0]);
	types->setInt(str[0]);
	types->setDbl(str[0]);
	types->setFlt(str[0]);
}

ScalarTypes *readTypeInt(std::string str) {
	ScalarTypes	*types;
	long		l;
	const char	*c_str;
	char		*end_str;
	
	c_str = str.c_str();
	l = strtol(c_str, &end_str, 10);
	if (c_str == end_str || l > std::numeric_limits<int>::max() ||
		l < std::numeric_limits<int>::min())
			throw ScalarConverter::ConversionFailedException();
	types = new ScalarTypes;
	types->setChar(static_cast<char>(l));
	types->setInt(l);
	types->setDbl(static_cast<double>(l));
	types->setFlt(static_cast<float>(l));
	return types;
}

ScalarTypes *readTypeFloat(std::string str) {
	ScalarTypes *types;
}

ScalarTypes *readTypeDouble(std::string str) {
	ScalarTypes	*types;
}

void ScalarConverter::convert(std::string str) {
	ScalarTypes	*types;
	
	try {
		if (isChar(str))
			types = readTypeChar(str);
		else if (isInt(str))
			types = readTypeInt(str);
		else if (isFloat(str))
			types = readTypeFloat(str);
		else if (isDouble(str))
			types = readTypeDouble(str);
		else
			//error handling
			return;
		}
	catch (ConversionFailedException &e)
		// conversion failed

	//output types
}



