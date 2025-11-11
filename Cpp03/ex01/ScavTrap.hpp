

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

//se heread todo menos los construncotores y operadores de sobrecarga que
//hay que configurarlos a mano

class	ScavTrap : virtual public ClapTrap //quizas haya que quitar el virtual para la hoja de coreccion
{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& copy);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& copy);
		void	guardGate(void);
		void	attack(const std::string& target);
};

#endif