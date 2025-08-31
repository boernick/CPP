/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:17:54 by nboer             #+#    #+#             */
/*   Updated: 2025/08/31 15:29:06 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <exception>

template<typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_n;
	public:
		class OutsideBoundsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Index out of bounds";
			}
		};
		
		Array<T>(){
			_array = new T[0];
			_n = 0;
		}
		
		Array<T>(unsigned int n){
			_array = new T[n]();
			_n = n;
		}
		
		~Array() {
			delete[] _array;
		}
		
		Array(Array &other) {
			_array = new T[other._n];
			_n = other._n;
		}
		
		Array<T> &operator=(const Array<T> &other) {
			if (this != &other){
				delete[] _array;
				_array = new T[other._n];
				_n = other._n;
				for (unsigned int i = 0; i < other._n; i++)
					_array[i] = T(other._array[i]);
			}
			return *this;
		}

		T &operator[](unsigned int i) const {
		if (i >= _n)
			throw OutsideBoundsException();
		return _array[i];
	}
		
		unsigned int size() const {
			return _n;
		}
};

#endif
