/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:37:07 by nboer             #+#    #+#             */
/*   Updated: 2025/10/29 17:18:50 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

int	main(void){	
	// high number
	size_t max = 50000;
	Span span(max);

	for (size_t i = 0; i < max; i++)
		span.addNumber(i);

	std::cout << "Shortest span = " << span.shortestSpan() << std::endl;
	std::cout << "Longest span = " << span.longestSpan() << std::endl;

	// number limit exception
	try {
		span.addNumber(max + 1);
	}
	catch (Span::NumberLimitException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	// invalid span
	Span invalid_span(1);
	try {
		invalid_span.longestSpan();
	}
	catch (Span::InvalidSpanException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// negative numbers
	Span s(5);
	s.addNumber(-10);
	s.addNumber(10);
	s.addNumber(0);
	std::cout << "Shortest span = " << s.shortestSpan() << std::endl;
	std::cout << "Longest span = " << s.longestSpan() << std::endl;

	// 2 numbers but size 3
	Span a(3);
	a.addNumber(1);
	a.addNumber(10);
	Span b = a;
	b.addNumber(100);
	try {
		std::cout << "a longest = " << a.longestSpan() << std::endl;
		std::cout << "b longest = " << b.longestSpan() << std::endl;
	}
	catch (Span::InvalidSpanException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// add numbers	
	std::list<int> lst;
	std::list<int> lst2;
	std::list<int> lst3;

	Span longspan(101);
	srand(time(0));
	for (int i = 0; i < 100; i++)
		lst.push_back(rand());

	longspan.addNumbers<std::list<int> >(lst.begin(), lst.end());
	std::cout << "Span size: " << longspan.size() << std::endl;
	std::cout << "Longspan longest = " << longspan.longestSpan() << std::endl;
	std::cout << "Longspan Shortest = " << longspan.shortestSpan() << std::endl;
	
	lst2.push_back(0);
	longspan.addNumbers<std::list<int> >(lst2.begin(), lst2.end());
	std::cout << "Second Longspan longest = " << longspan.longestSpan() << std::endl;
	std::cout << "Second Longspan shortest = " << longspan.shortestSpan() << std::endl;
	
	lst3.push_back(1);
	try {
		longspan.addNumbers<std::list<int> >(lst2.begin(), lst2.end());
		std::cout << "Third longspan longest = " << longspan.longestSpan() << std::endl;
		std::cout << "Third longspan shortest = " << longspan.shortestSpan() << std::endl;
	}
	catch (Span::NumberLimitException &e) {
		std::cout << "Exception: " << e.what() << std::endl;	
	}

}
