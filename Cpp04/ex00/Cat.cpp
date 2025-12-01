#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	this->type = copy.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat equal operator called" << std::endl;
	if (this == &copy)
		return *this;
	else {
		this->type = copy.getType();
		return *this;
	}
}

void Cat::makeSound(void) const {
	std::cout << "Miau" << std::endl;
}


