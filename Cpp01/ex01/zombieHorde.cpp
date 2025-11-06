
#include "Zombie.hpp"

//class zombie must have a Default constrcutor without parameters
//so the creation of a dinamic array of Zombies object can be created
//without problems


//usando el operator new que reserva memeria en modo raw, esta es la solucion mas eficiente
Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;

	void* rawMemory = operator new[](N * sizeof(Zombie));
	Zombie* zombieHorde = static_cast<Zombie*>(rawMemory);
	for (int i = 0; i < N; i++)
	{
		new (&zombieHorde[i]) Zombie(name + static_cast<char>(i + 1));
	}
	return (zombieHorde);
}

//creo qu esto va a mostrar el mensaje dos veces y puede que de mmery leak
void killHorde(int N, Zombie* horde)
{
	(void)N;
	if (!horde)
		return;
	for (int i = 0; i < N; i++)
	{
		horde[i].~Zombie();
	}
	operator delete[](horde);
}

//////////////////////////WRONG SOLUTIONN///////////////////////////////

//class zombie must have a Default constrcutor without parameters
//so the creation of a dinamic array of Zombies object can be created
//without problems

//thos solution is less efficient than use operator new beacause we create 2 objects
//for eceach zombie, the first one in heap memery with deafaul values and the other one
//on local memoery, then we copy de local object into the dinamic object
// Zombie* zombieHorde( int N, std::string name )
// {
// 	Zombie *zombieHorde;
// 	std::stringstream ss;
// 	std::string tmpName;
// 	int i;

// 	if (N <= 0)
// 		return (NULL);
// 	zombieHorde = new Zombie[N];
// 	if (zombieHorde == NULL)
// 		return (NULL);
// 	tmpName = name;
// 	i = 0;
// 	while (i < N)
// 	{
// 		ss << i + 1;
// 		tmpName = name + ss.str();
// 		zombieHorde[i] = Zombie(tmpName);
// 		tmpName = name;
// 		i++;
// 	}
// 	return (zombieHorde);
// }