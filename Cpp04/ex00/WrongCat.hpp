#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		virtual ~WrongCat();
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat& copy);
		void makeSound(void) const;
} ;

#endif