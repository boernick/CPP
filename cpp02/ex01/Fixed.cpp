/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:47:24 by nboer             #+#    #+#             */
/*   Updated: 2025/04/13 13:24:32 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fracbits = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed & cpy){
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed(const int number){
	std::cout << "Int constructor called" << std::endl;
	_value = number << _fracbits;
}

Fixed::Fixed(const float number){
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(number * (1 << _fracbits));
}

Fixed &Fixed::operator=(Fixed const &cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = cpy.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return (os << fixed.toFloat());
}
