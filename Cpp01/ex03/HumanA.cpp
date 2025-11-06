

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& Wea) : 
	name(name), weapon(Wea){}

void HumanA::attack(void) const
{
	std::cout << name << " attacks with their ";
	std::cout << weapon.getType() << std::endl;
}