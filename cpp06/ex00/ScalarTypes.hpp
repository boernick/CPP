/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:58:29 by nboer             #+#    #+#             */
/*   Updated: 2025/08/24 15:29:09 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

class ScalarTypes{
	private:
		char	_chr;
		int		_int;
		double	_dbl;
		float	_flt;
	public:
		ScalarTypes();
		ScalarTypes(char chr, int integer, double dbl, float flt);
		ScalarTypes(const ScalarTypes &other);
		~ScalarTypes();
		ScalarTypes &operator=(const ScalarTypes &other);

		char getChar();
		int getInt();
		double getDbl();
		float getFlt();

		void setChar(char chr);
		void setInt(int integer);
		void setDbl(double dbl);
		void setFlt(float flt);
};
