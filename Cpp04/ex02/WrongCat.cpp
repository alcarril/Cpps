#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(), type("Default WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	this->type = copy.getType();
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	std::cout << "WrongCat equal operator called" << std::endl;
	if (this == &copy)
		return *this;
	else {
		this->type = copy.getType();
		return *this;
	}
}

void WrongCat::makeSound(void) const {
	std::cout << "Ouch" << std::endl;
}
