/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:34:48 by nick              #+#    #+#             */
/*   Updated: 2025/10/29 17:07:22 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxsize(0) { }

Span::Span(unsigned int N) : _maxsize(N), _size(0) { }

Span::~Span() { }

Span::Span(const Span &src) { 
	_maxsize = src._maxsize;
	_size = src._size;
	_numbers = src._numbers;
}

Span &Span::operator=(const Span &src) {
	if (&src != this) {
		_size = src._size;
		_maxsize = src._maxsize;
		_numbers = src._numbers;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (_numbers.size() >= _maxsize)
		throw NumberLimitException();
	_size++;
	_numbers.push_back(num);
}

unsigned int Span::size() const {
	return _size;
}

int Span::shortestSpan() {
	int min_span = std::numeric_limits<int>::max();
	
	if (_numbers.size() < 2)
		throw Span::InvalidSpanException();
	for (unsigned int i = 0; i <= _numbers.size() - 1; i++) {
		for(unsigned int j = 0; j <= _numbers.size() - 1; j++) {
			if (i != j && abs(_numbers[i] - _numbers[j]) < min_span)
				min_span = abs(_numbers[i] - _numbers[j]);
		}
	}
	return min_span;
}

int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw InvalidSpanException();

	int min_val = *std::min_element(_numbers.begin(), _numbers.end());
	int max_val = *std::max_element(_numbers.begin(), _numbers.end());
	return max_val - min_val;
}

const char* Span::NumberLimitException::what() const throw() {
	return "Numbers limit reached";
}

const char* Span::InvalidSpanException::what() const throw() {
	return "No span can be found within the container";
}
