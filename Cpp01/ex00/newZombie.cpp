

#include "Zombie.hpp"

//Instance of a class zombie in dynamic memory and return its address.
//for the subject requirements we have to pass the string parameter by value. A better
//implementation would be to pass it by reference to avoid a copy of the string.
Zombie*	newZombie(std::string name) {
	Zombie* newZombie;

	newZombie = new Zombie(name);
	return (newZombie);
}