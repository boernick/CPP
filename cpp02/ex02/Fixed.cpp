/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:47:24 by nboer             #+#    #+#             */
/*   Updated: 2025/04/13 18:32:43 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fracbits = 8;

Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed & cpy){
	// std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed(const int number){
	// std::cout << "Int constructor called" << std::endl;
	_value = number << _fracbits;
}

Fixed::Fixed(const float number){
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(number * (1 << _fracbits));
}

Fixed &Fixed::operator=(Fixed const &cpy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value = cpy.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return (_value);
}

void Fixed::setRawBits(int const raw ){
	_value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fracbits);
}

int Fixed::toInt(void) const {
	return (_value >> _fracbits);
}

bool Fixed::operator>(const Fixed other) const {
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed other) const {
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed other) const {
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed other) const {
	return this->_value <= other._value;
}

bool Fixed::operator!=(const Fixed other) const {
	return this->_value != other._value;
}

bool Fixed::operator==(const Fixed other) const {
	return this->_value == other._value;
}

float Fixed::operator+(const Fixed other) const {
	float result;
	result = this->toFloat() + other.toFloat();
	return result;
}

float Fixed::operator-(const Fixed other) const {
	float result;
	result = this->toFloat() + other.toFloat();
	return result;
}

float Fixed::operator*(const Fixed other) const {
	float result;
	result = this->toFloat() * other.toFloat();
	return result;
}

float Fixed::operator/(const Fixed other) const {
	float result;
	result = this->toFloat() / other.toFloat();
	return result;
}

Fixed Fixed::operator++(){
	++this->_value;
	return *this;
}

Fixed Fixed::operator--(){
	--this->_value;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	this->_value--;
	return tmp;
}

Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	this->_value++;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	else
		return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	else
		return b;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed) {
	return (os << fixed.toFloat());
}
