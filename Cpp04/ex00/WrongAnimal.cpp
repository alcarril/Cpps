#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	this->type = copy.getType();
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << " WrongAnimal default destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	std::cout << " WrongAnimal equal operator called" << std::endl;
	if (this == &copy)
		return *this;
	else {
		this->type = copy.getType();
		return *this;
	}
}

void WrongAnimal::setType(const std::string& type) {
	this->type = type;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal make default sound" << std::endl;
}
