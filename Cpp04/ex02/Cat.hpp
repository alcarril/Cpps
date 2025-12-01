#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
#include <cstddef>

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		void setBrain(Brain* _brain);
		Brain *getBrain(void) const;
		void makeSound(void) const;
	private:
		Brain *_ptrBrain;
} ;

#endif