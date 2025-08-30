/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:17:54 by nboer             #+#    #+#             */
/*   Updated: 2025/08/30 18:25:24 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array {
	private:
	public:
		Array<T>();
		Array(unsigned int n);
		~Array();
		Array(Array &other);
		&operator=(Array &other);
		const int size() const;
};

#endif
