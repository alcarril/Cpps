
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void makeAnimalSound(Animal& animal) {
	std::cout << "Making sound of the animal passed as reference: ";
	animal.makeSound();
}

void makeAnimalSound(WrongAnimal& animal) {
	std::cout << "Making sound of the wrong animal passed as reference: ";
	animal.makeSound();
}

int	main(void) {
	std::cout << "STARTING LOCAL MEMORY TEST\n\n" << std::endl;
	Animal	localAnimal;
	Dog		localDog;
	Cat		localCat;

	localAnimal.makeSound();
	std::cout << localAnimal.getType() << std::endl;
	localDog.makeSound();
	std::cout << localDog.getType() << std::endl;
	localCat.makeSound();
	std::cout << localCat.getType() << std::endl;

	makeAnimalSound(localAnimal);
	makeAnimalSound(localDog);
	makeAnimalSound(localCat);

	std::cout << "\n POINTER TEST\n" << std::endl;
	Animal*	_ptrAnimal;

	_ptrAnimal = &localAnimal;
	_ptrAnimal->makeSound();
	std::cout << _ptrAnimal->getType() << std::endl;
	makeAnimalSound(*_ptrAnimal);
	_ptrAnimal = &localDog;
	_ptrAnimal->makeSound();
	std::cout << _ptrAnimal->getType() << std::endl;
	makeAnimalSound(*_ptrAnimal);
	_ptrAnimal = &localCat;
	_ptrAnimal->makeSound();
	std::cout << _ptrAnimal->getType() << std::endl;
	makeAnimalSound(*_ptrAnimal);
	
	std::cout << "\n REFERENCE TEST\n" << std::endl;
	Animal&		refAnimal = localAnimal;
	Dog&		refDog = localDog;
	Cat&		refCat = localCat;

	refAnimal.makeSound();
	std::cout << refAnimal.getType() << std::endl;
	makeAnimalSound(refAnimal);
	refDog.makeSound();
	std::cout << refDog.getType() << std::endl;
	makeAnimalSound(refDog);
	refCat.makeSound();
	std::cout << refCat.getType() << std::endl;
	makeAnimalSound(refCat);

	std::cout << "\n END OF LOCAL MEMORY TEST\n\n" << std::endl;

	std::cout << "STARTING DYNAMIC MEMORY TEST\n\n" << std::endl;
	_ptrAnimal = new Animal();
	_ptrAnimal->makeSound();
	std::cout << _ptrAnimal->getType() << std::endl;
	makeAnimalSound(*_ptrAnimal);
	delete _ptrAnimal;
	_ptrAnimal = new Dog();
	_ptrAnimal->makeSound();
	std::cout << _ptrAnimal->getType() << std::endl;
	makeAnimalSound(*_ptrAnimal);
	delete _ptrAnimal;
	_ptrAnimal = new Cat();
	_ptrAnimal->makeSound();
	std::cout << _ptrAnimal->getType() << std::endl;
	makeAnimalSound(*_ptrAnimal);
	delete _ptrAnimal;
	std::cout << "\n END OF DYNAMIC MEMORY TEST\n" << std::endl;

	std::cout << "STARTING WRONG ANIMAL TEST\n\n" << std::endl;
	WrongAnimal	localWrongAnimal;
	WrongCat		localWrongCat;

	localWrongAnimal.makeSound();
	std::cout << localWrongAnimal.getType() << std::endl;
	makeAnimalSound(localWrongAnimal);
	localWrongCat.makeSound();
	std::cout << localWrongCat.getType() << std::endl;
	makeAnimalSound(localWrongCat);

	WrongAnimal* _ptrWrongAnimal = &localWrongCat;
	_ptrWrongAnimal = &localWrongCat;
	_ptrWrongAnimal->makeSound();
	makeAnimalSound(*_ptrWrongAnimal);
	std::cout << _ptrWrongAnimal->getType() << std::endl;
	std::cout << "\n END OF WRONG ANIMAL TEST\n" << std::endl;

	std::cout << "WRONG DYNAMIC ANIMAL TEST\n\n" << std::endl;
	_ptrWrongAnimal = new WrongAnimal();
	_ptrWrongAnimal->makeSound();
	std::cout << _ptrWrongAnimal->getType() << std::endl;
	makeAnimalSound(*_ptrWrongAnimal);
	delete _ptrWrongAnimal;
	_ptrWrongAnimal = new WrongCat();
	_ptrWrongAnimal->makeSound();
	std::cout << _ptrWrongAnimal->getType() << std::endl;
	makeAnimalSound(*_ptrWrongAnimal);
	delete _ptrWrongAnimal;
	std::cout << "\n END OF WRONG DYNAMIC ANIMAL TEST\n" << std::endl;
	return 0;
}
