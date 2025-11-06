

#include "Weapon.hpp"

Weapon::Weapon() : type("") {}

Weapon::Weapon(const std::string& type)
{
	this->type = type;
}

const std::string&	Weapon::getType(void) const
{
	return(this->type);
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}