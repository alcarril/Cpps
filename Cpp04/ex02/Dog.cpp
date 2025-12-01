#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->_ptrBrain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	this->type = copy.getType();
	this->_ptrBrain = NULL;
	this->setBrain(copy.getBrain());
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
	delete _ptrBrain;
	_ptrBrain = NULL;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog equal operator called" << std::endl;
	if (this == &copy)
		return *this;
	else {
		this->type = copy.getType();
		this->setBrain(copy.getBrain());
		return *this;
	}
}

void Dog::makeSound(void) const {
	std::cout << "Guau" << std::endl;
}

Brain *Dog::getBrain(void) const {
	return this->_ptrBrain;
}

void Dog::setBrain(Brain* _brain) {
	if (this->_ptrBrain != NULL)
		delete _ptrBrain;
	// this->_ptrBrain = _brain; //sahllow copy
	this->_ptrBrain = new Brain(*_brain); //deep copy
}
