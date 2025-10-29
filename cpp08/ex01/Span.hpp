/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:29:09 by nick              #+#    #+#             */
/*   Updated: 2025/10/29 16:35:41 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <limits>

class Span {
	private:
		unsigned int		_maxsize;
		unsigned int		_size;
		std::vector<int>	_numbers;
	public:
		class NumberLimitException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		class InvalidSpanException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		unsigned int size() const;
		
		template <typename T>
		void addNumbers(typename T::iterator begin, typename T::iterator end) {
			if (std::distance(begin, end) > _maxsize - _size)
				throw Span::NumberLimitException();
			while (begin != end)
				addNumber(*(begin++));
		}
};
