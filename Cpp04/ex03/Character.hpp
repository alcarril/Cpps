#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include "ICharacter.hpp"

#define MAX_SLOTS 4

class Character : public ICharacter
{
	private:
		std::string* name;
		AMateria* _ptrMaterias[MAX_SLOTS];

	public:
		Character();
		Character(const std::string& name);
		Character(const Character& copy);
		Character& operator=(const Character& copy);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif