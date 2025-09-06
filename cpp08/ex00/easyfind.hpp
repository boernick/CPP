/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:31:31 by nboer             #+#    #+#             */
/*   Updated: 2025/09/06 18:09:16 by nboer            ###   ########.fr       */
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
