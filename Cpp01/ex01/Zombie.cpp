
#include "Zombie.hpp"

//class default constructor
Zombie::Zombie() : name("noname") {};

//class default constructor with parameters
Zombie::Zombie(const std::string& name) : name(name) {}

//announce metod
void Zombie::announce (void) const
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

//default destrcutor
Zombie::~Zombie()
{
	std::cout << name << " is destroyed." << std::endl;
}