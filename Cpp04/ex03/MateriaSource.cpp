#include "MateriaSource.hpp"

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

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource default destructor called" << std::endl;
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (_ptrMaterias[i] != NULL)
			delete _ptrMaterias[i];
	}
}

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
