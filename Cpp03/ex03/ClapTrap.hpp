

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class	ClapTrap
{
	protected:
		int					hitPoints; //health of ClapTrap object
		int					energyPoints; //energy
		unsigned int		attackDamage; //damage
		std::string			name;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& copy);
		virtual ~ClapTrap();
		ClapTrap& operator=(const ClapTrap& copy);
		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int ampunt);
};

#endif