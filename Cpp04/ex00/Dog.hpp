#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		void makeSound(void) const;
} ;

#endif