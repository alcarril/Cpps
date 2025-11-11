

#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class	DiamondTrap : public ScavTrap, public FragTrap
{
	protected:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& copy);
		~DiamondTrap();
		DiamondTrap&	operator=(const DiamondTrap& copy);
		void	attack(const std::string& target);
		void	whoAmI();
};

#endif

