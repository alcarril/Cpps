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

//a fucnion de clonacion fucnioan asi porque en el subjecto nos piden que retornemos una
//nueva materia del mismo tipo que la que clonamos cunado llamamos al metodo de esta funcion
//asi que usamos el operadotor new pra reservar memeria dinamica con el contructor de materia tipo
//cure por copia para que ponga en tipo en el campo (atributo) type de la materia.
AMateria* Cure::clone() const {
	AMateria* _ptrMateria;
	_ptrMateria = new Cure(*this);//
	return (_ptrMateria);
}
