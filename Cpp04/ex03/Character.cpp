#include "Character.hpp"

Character::Character() {
	std::cout << "Default character constrcutor called" << std::endl;
	this->name = NULL;
	for (int i = 0; i < MAX_SLOTS; i++) {
		_ptrMaterias[i] = NULL;
	}
}

Character::Character(const std::string& name) {
	std::cout << "Character parameter constrcutor called" << std::endl;
	this->name = new std::string(name);
		for (int i = 0; i < MAX_SLOTS; i++) {
		_ptrMaterias[i] = NULL;
	}
}

Character::Character(const Character& copy) {
	std::cout << "Character copy constrcutor called" << std::endl;
	this->name = NULL;
	for (int i = 0; i < MAX_SLOTS; i++) {
		_ptrMaterias[i] = NULL;
	}
	*this = copy;
}

Character::~Character() {
	std::cout << "Character default destructor called" << std::endl;
	delete name;
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (_ptrMaterias[i] != NULL)
			delete _ptrMaterias[i];
	}
}

Character& Character::operator=(const Character& copy) {
	if (this == &copy)
		return *this;
	if (name != NULL)
		delete this->name;
	this->name = new std::string(copy.getName());
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

std::string const & Character::getName() const {
	return *this->name;
}

void Character::equip(AMateria* m) {
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

void Character::unequip(int idx) {
	if (idx >= 0 && idx < MAX_SLOTS && _ptrMaterias[idx] != NULL) {
		this->_ptrMaterias[idx] = NULL;
	}
	else {
		std::cerr << "No materia in this slot\n";
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < MAX_SLOTS && _ptrMaterias[idx] != NULL) {
		_ptrMaterias[idx]->use(target);
	}
	else {
		std::cerr << "No materia in this slot\n";
	}
}

