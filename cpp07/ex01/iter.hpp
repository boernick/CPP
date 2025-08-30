/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:48:12 by nboer             #+#    #+#             */
/*   Updated: 2025/08/30 18:06:15 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ITER_H
#define ITER_h

template <typename T>
void iter(T arr[], std::size_t len, void (*f)(T)) {
	for (std::size_t i = 0; i < len; i++)
		(*f)(arr[i]);
}

#endif
