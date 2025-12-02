#include "Cure.hpp"

Cure::Cure() : AMateria() {
	std::cout << "Cure constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure(const std::string& type) : AMateria(type) {
	std::cout << "Cure parameter constructor called" << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria(copy) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
	//
}

Cure&	Cure::operator=(const Cure& copy) {
	if (this == &copy)
		return *this;
	else {
		this->type = copy.getType();
		return *this;
	}
}

void Cure::use(ICharacter& target) {
	std::cout << "*heals " << target.getName() << "'s wounds *\n";
}

AMateria* Cure::clone() const {
	AMateria* _ptrMateria;
	_ptrMateria = new Cure(*this);//
	return (_ptrMateria);
}
