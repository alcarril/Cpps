

#include "HumanA.hpp"

//Using initializer list to initialize the const members because
//the const members have to be initialized when the object is created
HumanA::HumanA(const std::string& name, const Weapon& Wea) : 
	name(name), weapon(Wea) {}

//The method is const because it does not modify the state of the object
void HumanA::attack(void) const {
	std::cout << name << " attacks with their ";
	std::cout << weapon.getType() << std::endl;
}
