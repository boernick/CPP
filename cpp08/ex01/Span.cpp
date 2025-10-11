/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:34:48 by nick              #+#    #+#             */
/*   Updated: 2025/09/07 15:06:42 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxsize(0) { }

Span::Span(unsigned int N) : _maxsize(N) { }

Span::~Span() { }

Span::Span(const Span &src) { 
	_maxsize = src._maxsize;
	_numbers = src._numbers;
}

void Span::addNumber(int num) {
	if (_numbers.size() >= _maxsize)
		throw NumberLimitException();
}

int Span::shortestSpan() {
	int min_span = std::numeric_limits<int>::max();
	
	if (_numbers.size() < 2)
		throw Span::InvalidSpanException();
	for (unsigned int i = 0; i <= _maxsize; i++) {
		for(unsigned int j = 0; j <= _maxsize; i++) {
			if (i != j && abs(_numbers[i] - _numbers[j]) < min_span)
				min_span = abs(_numbers[i] - _numbers[j]);
		}
	}
	return min_span;
}

int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw Span::InvalidSpanException();
	//CONTINUEE
}

const char* Span::NumberLimitException::what() const throw() {
	return "Numbers limit reached";
}

const char* Span::InvalidSpanException::what() const throw() {
	return "No span can be found within the container";
}
