/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:31:31 by nboer             #+#    #+#             */
/*   Updated: 2025/09/07 13:28:50 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

class ValueNotFoundException : std::exception {
	public:
		virtual const char* what() const throw() {
			return "Eror: Value not found";
		}
};

template<typename T>
typename T::value_type easyfind(const T &container, int value) {
	typename T::const_iterator it = find(container.begin(), container.end(), value);
		if (it == container.end())
			throw ValueNotFoundException();
		return *it;
}

#endif
