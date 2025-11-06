

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class Zombie
{
	private:
		const std::string name;

	public:
		Zombie(const std::string& name);
		void announce (void) const ;
		~Zombie();
};

Zombie*	newZombie(std::string name);
void randomChump( std::string name);

#endif