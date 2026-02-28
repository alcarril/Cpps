#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

//We use a reference to weapon because it is initialized in the constructor
//and then it doesn't need to be reallocated, which makes a reference more convenient.
//The HumanA (object) always has a weapon (object) assigned upon creation.
//Additionally, when the weapon type is changed using its method, 
//the reference automatically ensures that the human has the updated weapon.
/*
	NOTES:
	1.- The Weapon reference is const because HumanA can take a Weapon but 
		cannot change in his methods.
*/
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