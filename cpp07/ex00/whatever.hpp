/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:37:18 by nboer             #+#    #+#             */
/*   Updated: 2025/08/30 17:43:49 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

template <typename T>
void swap(T &x, T &y){
	T temp;
	temp = x;
	x = y;
	y = temp;
}

template <typename T>
const T &min(const T &x, const T &y){
	if (x < y)
		return x;
	else
		return y;
} 

template <typename T>
const T &max(const T &x, const T &y){
	if (x > y)
		return x;
	else
		return y;
} 

#endif
