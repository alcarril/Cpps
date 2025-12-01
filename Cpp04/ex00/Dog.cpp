#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	this->type = copy.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog equal operator called" << std::endl;
	if (this == &copy)
		return *this;
	else {
		this->type = copy.getType();
		return *this;
	}
}

void Dog::makeSound(void) const {
	std::cout << "Guau" << std::endl;
}
