#include "Character.hpp"

/*
	IMPORTANTE: Como los caracteres estan definido sa trves de una interfaz no hay que llamar
	al constructor de la interfaz (clase base), porque no tiene constrcutores. Se usa solo para
	el polimirfismo (especializacion)
*/
//como nos dicen en el subject que el inventario esta vacion hasta su construccion
//las los puntero a las materia que usa el caracter tiene que estar en NULL. Por ptra
//parte el puntero a las nombre no tiene porque ser memeria dinamica
Character::Character() {
	std::cout << "Default character constrcutor called" << std::endl;
	this->name = NULL;
	for (int i = 0; i < MAX_SLOTS; i++) {
		_ptrMaterias[i] = NULL;
	}
}

//como nos dicen en el subject que el inventario esta vacion hasta su construccion
//las los puntero a las materia que usa el caracter tiene que estar en NULL. Por ptra
//parte el puntero a las nombre no tiene porque ser memeria dinamica
Character::Character(const std::string& name) {
	std::cout << "Character parameter constrcutor called" << std::endl;
	this->name = new std::string(name);
		for (int i = 0; i < MAX_SLOTS; i++) {
		_ptrMaterias[i] = NULL;
	}
}

//ponermos el array de n punteros a materia y el nombre a NULL para poder usar el 
//operador de sobrecarga con el deep copy sin riesgo de hacer memery leaks o double free
Character::Character(const Character& copy) {
	std::cout << "Character copy constrcutor called" << std::endl;
	this->name = NULL;
	for (int i = 0; i < MAX_SLOTS; i++) {
		_ptrMaterias[i] = NULL;
	}
	*this = copy;
}

//el inventario de materias que tiene el caracter tiene que ser destruido cunado el caranter
//muere o se destruye, es decir que puede soltarlas y hacer que dejen de ser suyas pero que vivan
//en memeria si tiene almacenada alguna cunado mueres l materia deja de existir en memeria
Character::~Character() {
	std::cout << "Character default destructor called" << std::endl;
	delete name;
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (_ptrMaterias[i] != NULL)
			delete _ptrMaterias[i];
	}
}

//Cunado asignamos a una instancia de caraccrer otro caracter por el operador de copia
//para controlar el depp copy hay que borrar las materias que tuviese el caracter de la memoria
//y aso se puede reservar memoria para materias nuevas. Usamos clone de la propia intancia del 
//Objeto materia para retornar materias nuevas copiadas aunque se podria usar directamente
//la un instacia l objeto materi en memeria dinamica
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

//Cunado equipamos la materias tenemoss que buscar hueco consultando en inventario si se 
//encuentra se lade la materia pasa a ser posesion del caracter, si no hay hueco la materia 
//se tiene que borrar de memria (esto es por el ejemplo de main que nos ponen en el subject)
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

//cuando deequipamos la materia el caracter la deja de poseeer pero sigue existiendo en memeria 
//por eso es importante por eso hay que neter refencias en memria disponibles fuera del objeto
//para la meteria asi de puede veitar memeriy leaks, lo especifican en el subject
void Character::unequip(int idx) {
	if (idx >= 0 && idx < MAX_SLOTS && _ptrMaterias[idx] != NULL) {
		this->_ptrMaterias[idx] = NULL;
	}
	else {
		std::cerr << "No materia in this slot\n";
	}
}

//la funcion use del caracter lo unico que hace es llamar a la funcion use de la materia que 
//este almacenada en un slot concreto y se le da un target. Si esse slot esta vacio (NULL) es impmir
//unmensaje avisandolo
void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < MAX_SLOTS && _ptrMaterias[idx] != NULL) {
		_ptrMaterias[idx]->use(target);
	}
	else {
		std::cerr << "No materia in this slot\n";
	}
}

