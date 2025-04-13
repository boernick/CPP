/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:27:04 by nboer             #+#    #+#             */
/*   Updated: 2025/04/13 18:31:18 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
	static const int	_fracbits;
	int					_value;
public:
	Fixed();
	Fixed(const Fixed& cpy);
	Fixed(const int number);
	Fixed(const float number);
	Fixed &operator=(Fixed const &cpy);
	~Fixed();
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits (int const raw);
	bool operator>(const Fixed other) const;
	bool operator<(const Fixed other) const;
	bool operator>=(const Fixed other) const;
	bool operator<=(const Fixed other) const;
	bool operator==(const Fixed other) const;
	bool operator!=(const Fixed other) const;
	float operator+(const Fixed other) const;
	float operator-(const Fixed other) const;
	float operator*(const Fixed other) const;
	float operator/(const Fixed other) const;
	Fixed operator++(void);
	Fixed operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif
