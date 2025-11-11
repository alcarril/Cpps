

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

//se heread todo menos los construncotores y operadores de sobrecarga que
//hay que configurarlos a mano

class	ScavTrap : public ClapTrap //quizas haya qu ponerlo ne virtual para la coreccion
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