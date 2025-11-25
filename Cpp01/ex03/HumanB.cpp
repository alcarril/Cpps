#include "HumanB.hpp"

// The constructor for HumanB initializes the weapon pointer to NULL and assigns a name to HumanB.
// The name is constant, but the weapon pointer is not, as it allows HumanB to use weapons from other memory locations.
HumanB::HumanB(const std::string& name) : 
	name(name), weapon(NULL) {}

// This method sets the weapon by reference and assigns the address of that reference
// to the weapon pointer of the HumanB class. Both values are protected by const.
void HumanB::setWeapon(const Weapon& weapon) {
	this->weapon = &weapon;
}

// If the human has not chosen a weapon, the weapon pointer remains NULL by default.
// If a weapon is chosen, the method of the chosen weapon is called.
void HumanB::attack(void) const {
	if (weapon == NULL) {
		std::cout << "HumanB has no weapon\n";
	}
	else {
		std::cout << name << " attacks with their ";
		std::cout << weapon->getType() << std::endl;
	}
}
