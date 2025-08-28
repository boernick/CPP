/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:42:02 by nboer             #+#    #+#             */
/*   Updated: 2025/08/28 16:16:45 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ScalarTypes.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

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
	types->setInt(static_cast<int>(str[0]));
	types->setDbl(static_cast<double>(str[0]));
	types->setFlt(static_cast<float>(str[0]));
	return types;
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
	ScalarTypes	*types;
	float		flt;
	const char	*c_str;
	char		*end_str;
	
	c_str = str.c_str();
	flt = strtof(c_str, &end_str);
	if (c_str == end_str)
		throw ScalarConverter::ConversionFailedException();
	types = new ScalarTypes;
	types->setChar(static_cast<char>(flt));
	types->setInt(static_cast<int>(flt));
	types->setDbl(static_cast<double>(flt));
	types->setFlt(flt);
	return types;
}

ScalarTypes *readTypeDouble(std::string str) {
	ScalarTypes	*types;
	double		d;
	const char	*c_str;
	char		*end_str;

	c_str = str.c_str();
	d = strtod(c_str, &end_str);
	if (c_str == end_str)
		throw ScalarConverter::ConversionFailedException();
	types = new ScalarTypes;
	types->setChar(static_cast<char>(d));
	types->setInt(static_cast<int>(d));
	types->setDbl(d);
	types->setFlt(static_cast<float>(d));
	return types;
}

void err_handler(std::string message)
{
	std::cout << message << std::endl;
}

void print_types(ScalarTypes& types) {
	long 		l;
	std::string	round_dec;

	if (types.getFlt() == types.getInt())
		round_dec = ".0";
	else
		round_dec = "";
	l = static_cast<long>(types.getDbl());
	if (l < std::numeric_limits<char>::min() || l > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(types.getChar()))
		std::cout << "char: '" << types.getChar() << "'" << std::endl;
	else
		std::cout << "char: Non displayable"  << std::endl;
	if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << types.getInt() << std::endl;
	std::cout << "float: " << types.getFlt() << round_dec << 'f' << std::endl;
	std::cout << "double: " << types.getDbl() << round_dec << std::endl;
}

void ScalarConverter::convert(std::string str) {
	ScalarTypes	*types;
	
	try {
		if (isInt(str))
			types = readTypeInt(str);
		else if (isChar(str))
			types = readTypeChar(str);
		else if (isFloat(str))
			types = readTypeFloat(str);
		else if (isDouble(str))
			types = readTypeDouble(str);
		else {
			err_handler("Error during conversion");
			return;
		}
	}
	catch (ConversionFailedException &e) {
		err_handler(e.what());
		return;
	}
	print_types(*types);
	if (types)
		delete types;
}

const char* ScalarConverter::ConversionFailedException::what() const throw() {
	return ("Conversion failed");
}
