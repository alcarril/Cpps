#include "MateriaSource.hpp"

/*
	se ponen las pùntero  de los metdos mienbre a NULL para contronlar iniciliamente el depp
	Copy. Ademas como es un clase que hereda de un interfaz no tiene se tiene que usar su
	contructor
*/
MateriaSource::MateriaSource() {
	std::cout << "Default MateriaSource constrcutor called" << std::endl;
	for (int i = 0; i < MAX_SLOTS; i++) {
		_ptrMaterias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	std::cout << "MateriaSource copy constrcutor called" << std::endl;
	for (int i = 0; i < MAX_SLOTS; i++) {
		_ptrMaterias[i] = NULL;
	}
	*this = copy;
}

//como las mteria sparendidas se mantienen dentro del materia sourdce cuando se 
//crean hay que destruiralas en memeria dinamica cunado se destruye el materia source
MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource default destructor called" << std::endl;
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (_ptrMaterias[i] != NULL)
			delete _ptrMaterias[i];
	}
}

//se copia un materia source a iotra controlando el depp copy para evitar memery leaks
MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
	if (this == &copy)
		return *this;
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (_ptrMaterias[i] != NULL)
			delete _ptrMaterias[i];
		if(copy._ptrMaterias[i] != NULL)
			_ptrMaterias[i] = copy._ptrMaterias[i]->clone();
		else
			_ptrMaterias[i] = NULL;
	}
	return *this;
}

//Guarda las materias que se pasan desde memerai reservada en un ainstacia superior
//cuando el almacen de materias disponles esta lleno, se borra la materia para controlar
//que no se haga un memeria leak ya que la funcion no tiene retornoy demoneto no estamis usando
//try y cath para controlarlo. Admeas se informa por panrtalla de que esta lleno el amacen in
//dependiente de matria source
void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (this->_ptrMaterias[i] == NULL) {
			_ptrMaterias[i] = m;
			break ;
		}
		if (i == MAX_SLOTS - 1) {
			delete m;
			std::cerr << "All slots are ocuped\n";
		}
	}
}

//Retorna la materia que se ha ha aprendido. Por lo que el numero de materias aprendidas
//es limitado cunado se han aprendido un numero de materias no se pueden apreder mas porque
//cunado llamamaos al metodo create materia no se desaprenden
AMateria* MateriaSource::createMateria(std::string const & type) {
	AMateria* ret = NULL;
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (this->_ptrMaterias[i] != NULL && this->_ptrMaterias[i]->getType() == type) {
			if (ret != NULL)
				delete ret;
			ret = this->_ptrMaterias[i]->clone();
		}
	}
	if (ret == NULL)
		std::cerr << "Materia of type " << type << " not found\n";
	return ret;
}
