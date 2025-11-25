
#include "Zombie.hpp"

//Using placement new to construct each Zombie in the allocated memory
//using operator new to allocate raw memory for N Zombies, because if we use new Zombie[N]
//it will call the default constructor for each Zombie.
// Zombie* zombieHorde(int N, std::string name) {
// 	if (N <= 0) {
// 		std::cerr << "Horde need more Zombies...\n";
// 		return (NULL);
// 	}
// 	void* rawMemory = operator new[](N * sizeof(Zombie));
// 	Zombie* zombieHorde = static_cast<Zombie*>(rawMemory);
// 	for (int i = 0; i < N; i++) {
// 		std::stringstream ss;
// 		ss << name << (i + 1); // strjoing number to name
// 		new (&zombieHorde[i]) Zombie(ss.str());
// 	}
// 	return (zombieHorde);
// }

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0) {
		std::cerr << "Horde need more Zombies...\n";
		return (NULL);
	}
	Zombie* zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombieHorde[i].set_name(name);

	return (zombieHorde);
}


//the killHorde function calls the destructor for each Zombie
//and then deallocates the memory using operator delete[]
//to match the operator new[] used in zombieHorde.
//it dont calls destrcutor twice because we are manually calling the destructor
//for each Zombie before deallocating the memory.
void killHorde(Zombie* horde) {
	if (!horde)
		return;
	 delete[] (horde);
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
// 		zombieHorde[i].setName(tmpName);
// 		tmpName = name;
// 		i++;
// 	}
// 	return (zombieHorde);
// }