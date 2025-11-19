
#include "Zombie.hpp"

//Instance of a class zombie in local memory and announce.
//We use local memory so we don't need to delete it. For the subject
//requirements we hace to pass the string parametrer by value. A better imple
//mentation would be to pass it by reference to avoid a copy of the string.
void	randomChump( std::string name) {
	Zombie random(name);

	random.announce();
}