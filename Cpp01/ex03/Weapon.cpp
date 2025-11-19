

#include "Weapon.hpp"

//Default constructor initializes type to an empty string
Weapon::Weapon() : type("") {}

//The parameter type is constantly referenced to avoid copying overhead
//and to allow passing temporary string objects. We dont user initializer list
//here but we could.
Weapon::Weapon(const std::string& type) {
	this->type = type;
}

//the function is const beacause it does not modify the state of the object
const std::string&	Weapon::getType(void) const {
	return(this->type);
}

//using a const reference to avoid copying overhead and to allow
//passing temporary string objects. Is not const because it modifies the state
//of the object.
void Weapon::setType(const std::string& type) {
	this->type = type;
}
