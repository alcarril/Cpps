
#include "Zombie.hpp"

//class default constructor: we add this constrcutor to give a default name
//because when we create an array of zombies we need to call a default constructor
Zombie::Zombie() : name("noname") {};

//class default constructor with parameters
Zombie::Zombie(const std::string& name) : name(name) {}

//announce metod
void Zombie::announce (void) const {
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

//default destrcutor
Zombie::~Zombie() {
	std::cout << name << " is destroyed." << std::endl;
}


//for setter option
// void Zombie::setName(const std::string& name) {
// 	this->name = name;
// }