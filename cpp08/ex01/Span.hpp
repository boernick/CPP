/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:29:09 by nick              #+#    #+#             */
/*   Updated: 2025/09/07 15:01:30 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_h

#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>


class Span {
	private:
		unsigned int		_maxsize;
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
		~Span();
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
};

#endif
