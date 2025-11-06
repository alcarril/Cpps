

#include "Zombie.hpp"

//When the Zombie object is deleted in heap memery (by prorgam)
//or is deleted in stack memery by the kernel (system) if the
//class has a destrcutor is called automatly
int main(void)
{
	Zombie* heapZombie;
	Zombie* heapZombie1;
	std::string name1;

	heapZombie = newZombie("heapSlok");
	if (heapZombie == NULL)
		return (1);
	heapZombie->announce();;
	delete heapZombie;

	name1 = "heapMorty";
	heapZombie1 = newZombie(name1);
	if (heapZombie1 == NULL)
		return (1);
	heapZombie1->announce();
	delete heapZombie1;

	randomChump("localLexter");
	randomChump("localFriedrich");
	return (1);
}
