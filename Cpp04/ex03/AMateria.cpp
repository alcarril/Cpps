#include "AMateria.hpp"

AMateria::AMateria() : type("") {
	std::cout << "AMAteria constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) {
	std::cout << "AMAteria parameter constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria& copy) {
	std::cout << "AMAteria copy constructor called" << std::endl;
	*this = copy;
}

AMateria::~AMateria() {
	std::cout << "AMAteria destructor called" << std::endl;
	//
}

AMateria&	AMateria::operator=(const AMateria& copy) {
	if (this == &copy)
		return *this;
	else {
		this->type = copy.getType();
		return *this;
	}
}

std::string const & AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "Default a materia use\n";
}
