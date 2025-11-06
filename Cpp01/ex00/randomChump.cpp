
#include "Zombie.hpp"

//Instance of a class zombie in local memory nad announce
void randomChump( std::string name)
{
	Zombie random(name);

	random.announce();
}