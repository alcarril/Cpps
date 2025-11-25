

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>
#include <cstdlib>
#include <sstream>

class Zombie
{
	private:
		std::string name;


	public:
		Zombie();
		Zombie(const std::string& name);
		void announce (void) const ;
		void set_name (std::string &) ;
		~Zombie();
};
Zombie* zombieHorde( int N, std::string name );
void killHorde(Zombie* horde);

//optio 2 with setter
// class Zombie
// {
// 	private:
// 		std::string name;

// 	public:
// 		Zombie();
// 		Zombie(const std::string& name);
// 		void announce (void) const ;
// 		void setName(const std::string& name);
// 		~Zombie();
// };

#endif