

#include "Zombie.hpp"

//in this class we also can use a setter instead of have a parameter constrcutor
//and use a getter to get the name when we need it.

//class default constructor with parameters
Zombie::Zombie(const std::string& name) : name(name) {}


//default destrcutor
Zombie::~Zombie() {
	std::cout << name << " is destroyed." << std::endl;
}

//announce metod: we use const because we don't want to modify any member variables
void	Zombie::announce (void) const {
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}