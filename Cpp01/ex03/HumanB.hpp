#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

//Human name protected with const (makes sense because it is only
//assigned in the class constructor)
//Pointer to weapon protected with const to prevent altering the value
//of the Weapon object it points to
//We use a pointer instead of a reference because HumanB has the option
//to change weapons, pointing to another memory address.
class HumanB
{
	private:
		const std::string name; // 1
		const Weapon*	weapon; // 2
	public:
		HumanB(const std::string& name);
		void setWeapon(const Weapon& weap);
		void attack() const;
};

#endif