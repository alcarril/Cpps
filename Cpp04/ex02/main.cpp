
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
	// Animal	localAnimal;
	Dog		localDog;
	Cat		localCat;

	// localAnimal.makeSound();
	// std::cout << localAnimal.getType() << std::endl;
	localDog.makeSound();
	std::cout << localDog.getType() << std::endl;
	localCat.makeSound();
	std::cout << localCat.getType() << std::endl;

	// makeAnimalSound(localAnimal);
	makeAnimalSound(localDog);
	makeAnimalSound(localCat);

	std::cout << "\n POINTER TEST\n" << std::endl;
	Animal*	_ptrAnimal;

	// _ptrAnimal = &localAnimal;
	// _ptrAnimal->makeSound();
	// std::cout << _ptrAnimal->getType() << std::endl;
	// makeAnimalSound(*_ptrAnimal);
	_ptrAnimal = &localDog;
	_ptrAnimal->makeSound();
	std::cout << _ptrAnimal->getType() << std::endl;
	makeAnimalSound(*_ptrAnimal);
	_ptrAnimal = &localCat;
	_ptrAnimal->makeSound();
	std::cout << _ptrAnimal->getType() << std::endl;
	makeAnimalSound(*_ptrAnimal);
	
	std::cout << "\n REFERENCE TEST\n" << std::endl;
	// Animal&		refAnimal = localAnimal;
	Dog&		refDog = localDog;
	Cat&		refCat = localCat;

	// refAnimal.makeSound();
	// std::cout << refAnimal.getType() << std::endl;
	// makeAnimalSound(refAnimal);
	refDog.makeSound();
	std::cout << refDog.getType() << std::endl;
	makeAnimalSound(refDog);
	refCat.makeSound();
	std::cout << refCat.getType() << std::endl;
	makeAnimalSound(refCat);

	std::cout << "\n END OF LOCAL MEMORY TEST\n\n" << std::endl;

	std::cout << "STARTING DYNAMIC MEMORY TEST\n\n" << std::endl;
	// _ptrAnimal = new Animal();
	// _ptrAnimal->makeSound();
	// std::cout << _ptrAnimal->getType() << std::endl;
	// makeAnimalSound(*_ptrAnimal);
	// delete _ptrAnimal;
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

	std::cout << "\n\n //////////////EX01 TEST///////////////\n\n";
	std::cout << "\nLOCAL Creating an array of Animals (Dogs and Cats):\n" << std::endl;
	//test de array local de animales -> object shifting
	unsigned int _nAnimals = 4;
	// Animal	_arrAnimals[_nAnimals];
	// for (unsigned int i = 0; i < _nAnimals; i++) {
	// 	if (i < _nAnimals / 2) {
	// 		_arrAnimals[i] = Cat();
	// 		_arrAnimals[i].makeSound();
	// 	}
	// 	else {
	// 		_arrAnimals[i] = Dog();
	// 		_arrAnimals[i].makeSound();
	// 	}

	// }

	std::cout << "\nDYNAMIC Creating an array of Animals (Dogs and Cats):\n" << std::endl;
	//test de array dinamico de animales -> punteros a objetos
	Animal *_ptrAnimals[_nAnimals];
	for (unsigned int i = 0; i < _nAnimals; i++) {
		if (i < _nAnimals / 2) {
			_ptrAnimals[i] = new Cat();
			_ptrAnimals[i]->makeSound();
			std::cout << _ptrAnimals[i]->getType() << std::endl;
		}
		else {
			_ptrAnimals[i] = new Dog();
			_ptrAnimals[i]->makeSound();
			std::cout << _ptrAnimals[i]->getType() << std::endl;
		}
	}

	for (unsigned int i = 0; i < _nAnimals; i++) {
		delete _ptrAnimals[i];
	}

	std::cout << "\n TESTING DEEP COPY\n" << std::endl;
	//test de memory leaks
	Brain *brain = new Brain();
	Dog Pitbull;
	Dog Rotweiller;
	Dog	Golden;
	Dog	Canario;
	Cat Garfield;

	//polimorfismo
	Animal *_ptrAnimal1 = new Dog();
	_ptrAnimal1->makeSound();
	delete _ptrAnimal1;

	_ptrAnimal1 = new Cat(Garfield);
	_ptrAnimal1->makeSound();
	delete _ptrAnimal1;

	//comporbamos que no se haga el shallow copy para los memria leaks
	Canario = Golden;//operador de sobrecarga
	Pitbull.setBrain(brain);
	Rotweiller.setBrain(brain);
	Garfield.setBrain(Pitbull.getBrain());
	delete brain;

	std::cout << "\n\nEX02 STARTTING TESTS\n\n" << std::endl;
	//Los test de este ejercicio se basn en decomentar las instancias a animales de la clase abstracta AAnimal
	return 0;
}
