

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class	ClapTrap
{
	//for correction maybe this has to be in protected
	private:
		int					hitPoints; //health of ClapTrap object
		int					energyPoints; //energy
		unsigned int		attackDamage; //damage
		std::string			name;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& copy);
		~ClapTrap();////for correction maybe this has to be in virtual
		ClapTrap& operator=(const ClapTrap& copy);
		void	attack(const std::string& target);//for correction maybe this has to be in virtual
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int ampunt);
};

#endif