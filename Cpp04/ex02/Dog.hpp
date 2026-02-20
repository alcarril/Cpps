#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
#include <cstddef>

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		void setBrain(Brain* _brain);
		Brain *getBrain(void) const;
		void makeSound(void) const;
	private:
		Brain *_ptrBrain;
} ;

#endif
