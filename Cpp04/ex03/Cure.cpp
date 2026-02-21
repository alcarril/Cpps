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

//iguiendno als intrucciones del sbject cunado se llama a esta funcion le podemos pasar
//un caranter de calquier tipo si hubiese as de uno que hereda de la interfaz Icaracter
//aunqolo hayamos definido uno. el objeto caracter tiene un campo name que usamso a trvae sde su 
//getter encapsulacion para obtejer el strinf del nombre del caracter y pasarselo a oprador de sorecarga
void Cure::use(ICharacter& target) {
	std::cout << "*heals " << target.getName() << "'s wounds *\n";
}

//en el subject nos piden que clone retorn una nueva instancia de la materia
//con el mimo topo asi que instanciamos el objeto desde memroia dinamica con la 
//clausula new
AMateria* Cure::clone() const {
	AMateria* _ptrMateria;
	_ptrMateria = new Cure(*this);//
	return (_ptrMateria);
}
