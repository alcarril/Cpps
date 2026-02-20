#ifndef ICHARACTER_H
#define ICHARACTER_H

#include <string>
#include <iostream>
#include "AMateria.hpp"

class AMateria;

//esto de declarar aqui no se si v en conta de la nomas de 42
class ICharacter
{
	public:
		virtual ~ICharacter() {
			std::cout << "Interface caracter default destrcutor called" << std::endl;
		}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
