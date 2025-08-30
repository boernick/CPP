/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:32:40 by nboer             #+#    #+#             */
/*   Updated: 2025/08/30 16:24:29 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base* generate(void) {
	switch (rand() % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return (NULL);
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "Class A" << std::endl;
	} catch (std::exception &e) { }
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "Class B" << std::endl;
	} catch (std::exception &e) { }
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "Class C" << std::endl;
	} catch (std::exception &e) { }
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
}

int main(void) {
	Base *p;

	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		p = generate();
		identify(p);
		identify(*p);
		delete p;
	}
	return (0);
}

