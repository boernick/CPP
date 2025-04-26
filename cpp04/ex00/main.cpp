/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:09:59 by nboer             #+#    #+#             */
/*   Updated: 2025/04/26 14:20:48 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
	std::cout << std::endl;

	const WrongAnimal* hans = new WrongAnimal();
	const WrongAnimal* k = new WrongDog();
	const WrongAnimal* l = new WrongCat();
	std::cout << k->getType() << " " << std::endl; 
	std::cout << l->getType() << " " << std::endl;
	k->makeSound(); //will output the cat sound!
	l->makeSound();
	hans->makeSound();
	delete hans;
	delete k;
	delete l;
	std::cout << std::endl;
	std::cout << std::endl;


	
	return 0;
}
