
#include "HumanB.hpp"

//El constructor de human b nos permite poner el puntero a NULL y
//darle nombre al humanb (el nombre es constante pero el puntero no
//porque nos srive para conger armas de otras direcciones de memoria)
HumanB::HumanB(const std::string& name) : 
	name(name), weapon(NULL) {}

//Le pasamos weapon por referencia y escogemos la dreccion de esa
//referencia y la igualamos al puntero weapon de la clase human
//ambos los valores de ambas direcciones estan progtegidos con const
void HumanB::setWeapon(const Weapon& weapon) {
	this->weapon = &weapon;
}

//si el humano no ha escogido el arma esta en NULL por defecto
//si la ha escogido se llama al metodo del arma escogida
void HumanB::attack(void) const {
	if (weapon == NULL)
	{
		std::cout << "HumanB has no weapon\n";
	}
	else
	{
		std::cout << name << " attacks with their ";
		std::cout << weapon->getType() << std::endl;
	}
}
