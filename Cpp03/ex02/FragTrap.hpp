
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class	FragTrap : public ClapTrap //quizas haya que ponerlo en virtual para la coreccion
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