/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:58:21 by nboer             #+#    #+#             */
/*   Updated: 2025/08/24 15:35:05 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarTypes.hpp"

ScalarTypes::ScalarTypes() :
_chr(0), _int(0), _dbl(0.0), _flt(0.0f) {}

ScalarTypes::ScalarTypes(char chr, int integer, double dbl, float flt) :
_chr(chr), _int(integer), _dbl(dbl), _flt(flt) {}

ScalarTypes::ScalarTypes(const ScalarTypes &other) :
_chr(other._chr), _int(other._int), _dbl(other._dbl), _flt(other._flt) {}

ScalarTypes::~ScalarTypes() {}

ScalarTypes &ScalarTypes::operator=(const ScalarTypes &other){
	if (this != &other) {
		this->_chr = other._chr;
		this->_int = other._int;
		this->_dbl = other._dbl;
		this->_flt = other._flt;
	}
	return (*this);
}

char ScalarTypes::getChar(){
	return _chr;
}

int ScalarTypes::getInt(){
	return _int;
}

double ScalarTypes::getDbl(){
	return _dbl;
}

float ScalarTypes::getFlt(){
	return _flt;
}

void ScalarTypes::setChar(char chr){
	_chr = chr;
}

void ScalarTypes::setInt(int integer){
	_int = integer;
}

void ScalarTypes::setDbl(double dbl){
	_dbl = dbl;
}

void ScalarTypes::setFlt(float flt){
	_flt = flt;
}
