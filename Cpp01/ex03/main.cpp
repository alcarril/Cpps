#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon club = Weapon("crude spiked club");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon anotherClub = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(anotherClub);
	jim.attack();
	anotherClub.setType("some other type of club");
	jim.attack();

	return 0;
}