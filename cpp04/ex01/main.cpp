/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:09:59 by nboer             #+#    #+#             */
/*   Updated: 2025/05/04 18:39:16 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* meta = 	new Animal();
	const Animal* j = 		new Dog();
	const Animal* i = 		new Cat();
	const	Cat* test			= new Cat();
	Animal *animals[100];

	std::cout << std::endl;

	// test types
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;

	// test sounds
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	
	std::cout << std::endl;
	
	//test
	((Cat *) i)->getBrain()->setIdea(0, "The earth is round, but not a perfect sphere");
	const Cat a(*((const Cat *)i));
	std::cout << "-- Create cat B" << std::endl;
	Cat b = *test;
	std::cout << "-- Cat B created" << std::endl;
	std::cout << "-- Create Cat D" << std::endl;
	Cat d;
	d = *(Cat *)i;
	std::cout << "-- Cat D created" << std::endl;
	Cat e;

	std::cout << std::endl;

	// test
	a.getBrain()->setIdea(0, "The earth is as flat as a pancake");

	std::cout << "Idea of I: " << ((Cat *)i)->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea of A: " << a.getBrain()->getIdea(0) << std::endl;

	// delete animals
	delete meta;
	delete j;//should not create a leak
	delete i;
	delete test;
	
	std::cout << std::endl;

	// loop and assign cats + dogs
	for (int i = 0; i < 3; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	
	// delete animals
	for (int i = 0; i < 3; i++)
		delete animals[i];
	
	return 0;
}
