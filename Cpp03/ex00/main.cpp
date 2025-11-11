

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	alf("alf");
	ClapTrap	jordi(ClapTrap("jordi"));
	ClapTrap	fakejordi(jordi);

	std::cout << std::endl;
	alf.attack("your mother");
	jordi.attack("your grandmother");
	fakejordi.attack("your cousin");

	std::cout << std::endl;
	int i = 0;
	while (i++ < 10)
		alf.takeDamage(1);
	alf.takeDamage(5);

	std::cout << std::endl;
	jordi.takeDamage(5);
	jordi.beRepaired(5);
	jordi.takeDamage(11);
	jordi.takeDamage(1);
	std::cout << std::endl;
	return(0);
}