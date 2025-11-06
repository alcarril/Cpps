


#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

//usamos la referencia a weapon porque se inicliaza en el constructor
//y despues no tiene que realocar, por eso es mas comoda  una referencia. Ademas
//cuando con el metodo de weapon cambiamos el tipo automaticamente la referencia
//hace que el humano tenga otra arma
class HumanA
{
	private:
		const std::string name;
		const Weapon&	weapon;
	public:
		HumanA(const std::string& name, const Weapon& Wea);
		void attack() const;
};

#endif