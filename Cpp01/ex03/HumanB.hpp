
#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

//Nombre de humano protegido con const (tiene sentido porque solo
//se le da el nombre en el constrcutor de la clase)
//Puntero a wepon portegido con const para no poder altenara el valor
//de la direccion donde apunte
//usamos puntero en vez de una referencai porque el humano b tiene la opcion
//de cambiar de arma, apuntar a otra direccion de memoria. Esto no depende unicamente
//de que el arma o espacio de memeria apuntado cambie
class HumanB
{
	private:
		const std::string name;
		const Weapon*	weapon;
	public:
		HumanB(const std::string& name);
		void setWeapon(const Weapon& weap);
		void attack() const;
};

#endif