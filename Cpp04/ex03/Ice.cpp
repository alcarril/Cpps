#include "Ice.hpp"

Ice::Ice() : AMateria() {
	std::cout << "Ice constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const std::string& type) : AMateria(type) {
	std::cout << "Ice parameter constructor called" << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
	//
}

Ice&	Ice::operator=(const Ice& copy) {
	if (this == &copy)
		return *this;
	else {
		this->type = copy.getType();
		return *this;
	}
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria* Ice::clone() const {
	AMateria* _ptrMateria;
	_ptrMateria = new Ice(*this);//
	return (_ptrMateria);
}