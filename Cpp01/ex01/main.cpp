

#include "Zombie.hpp"

int main(int argc, char **argv)
{
	Zombie *horde;
	std::string name;
	int numZombies;

	if (argc != 3)
	{
		std::cerr << "Arguments error\n";
		return (1);
	}
	numZombies = std::atoi(argv[1]);
	if (numZombies == 0)
	{
		std::cerr << "Horde need more Zombies...\n";
		return (1);
	}
	name = argv[2];
	horde = zombieHorde(numZombies, name);
	if (horde == NULL)
		return (1);
	for(int i = 0; i < numZombies; i++)
		horde[i].announce();
	killHorde(numZombies, horde);
	return (0);
}