#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_ptrBrain = new Brain();
}

//Ponemso el puntero a brain a NULL para que cuanado llamemos al setter del brain
//y tengamos que eliminar el brain actual no eleminemos el memeria resifual, ya que lo controlamos
///en el setter mirando si el puntero BRAInesta en NULL. Otra opcion seria en la declaracion de la
//platilla de la clase poner le puntero a NULL por defecto.
Cat::Cat(const Cat& copy) : Animal(copy) {
	this->type = copy.getType();
	this->_ptrBrain = NULL;
	this->setBrain(copy.getBrain());
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
	delete _ptrBrain;
	_ptrBrain = NULL;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat equal operator called" << std::endl;
	if (this == &copy)
		return *this;
	else {
		this->type = copy.getType();
		this->setBrain(copy.getBrain());
		return *this;
	}
}

void Cat::makeSound(void) const {
	std::cout << "Miau" << std::endl;
}

Brain *Cat::getBrain(void) const {
	return this->_ptrBrain;
}

void Cat::setBrain(Brain* _brain) {
	if (this->_ptrBrain != NULL)
		delete _ptrBrain;
	// this->_ptrBrain = _brain; //shallow copy
	this->_ptrBrain = new Brain(*_brain);//deep copy
}
