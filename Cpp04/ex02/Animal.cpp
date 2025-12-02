#include "Animal.hpp"

Animal::Animal() : type("Default Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) {
	this->type = copy.getType();
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal default destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << "Animal equal operator called" << std::endl;
	if (this == &copy)
		return *this;
	else {
		this->type = copy.getType();
		return *this;
	}
}

void Animal::setType(const std::string& type) {
	this->type = type;
}

std::string Animal::getType(void) const {
	return this->type;
}

