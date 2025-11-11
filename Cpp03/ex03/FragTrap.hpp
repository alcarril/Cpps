
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& copy);
		~FragTrap();
		FragTrap& operator=(const FragTrap& copy);
		void highFivesGuys(void);
};

#endif