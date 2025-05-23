/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:27:04 by nboer             #+#    #+#             */
/*   Updated: 2025/04/12 16:09:21 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
	static const int	_fracbits;
	int					_value;
public:
	Fixed();
	Fixed(const Fixed& cpy);
	Fixed &operator=(Fixed const &cpy);
	~Fixed();
	int					getRawBits(void) const;
	void 				setRawBits (int const raw);
};

#endif
