

#include "iter.hpp"

int main() {
	// Test 1: array de enteros
	const int arrInt[] = {1, 2, 3, 4, 5};
	const size_t lenInt = sizeof(arrInt) / sizeof(arrInt[0]);

	std::cout << "Array de enteros antes de incrementar: ";
	iter(arrInt, lenInt, print<int>);
	std::cout << std::endl;
	
	// iter(arrInt, lenInt, increment<int>); // -> si se descomenta dara error de compilacion porque no podemos modificar un array de const

	std::cout << "Array de enteros después de incrementar: ";
	iter(arrInt, lenInt, print<int>);
	std::cout << std::endl << std::endl;

	// Test 2: array de doubles
	double arrDouble[] = {1.5, 2.5, 3.5};
	const size_t lenDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);

	std::cout << "Array de doubles antes de incrementar: ";
	iter(arrDouble, lenDouble, print<double>);
	std::cout << std::endl;

	iter(arrDouble, lenDouble, increment<double>);

	std::cout << "Array de doubles después de incrementar: ";
	iter(arrDouble, lenDouble, print<double>);
	std::cout << std::endl << std::endl;

	// Test 3: array de strings
	std::string arrStr[] = {"hello", "world"};
	const size_t lenStr = sizeof(arrStr) / sizeof(arrStr[0]);

	std::cout << "Array de strings antes de append_exclamation: ";
	iter(arrStr, lenStr, print<std::string>);
	std::cout << std::endl;

	iter(arrStr, lenStr, appendExclamation);

	std::cout << "Array de strings después de append_exclamation: ";
	iter(arrStr, lenStr, print<std::string>);
	std::cout << std::endl;

	//Extra test:
	//Test 4: Funcion con punteros
	int arrInts[] = {3, 4}; //No puede ser const
	const size_t lenInts = sizeof(arrStr) / sizeof(arrStr[0]);

	std::cout << std::endl;
	std::cout << "Array de numeros antes de modficacion por puntero: ";
	iter(arrInts, lenInts, print<int>);
	std::cout << std::endl;

	iter2(arrInts, lenInts, ptrNoconst<int>);
		
	std::cout << "Array de numeros después de modficacion por puntero: ";
	iter(arrInts, lenInts, print<int>);
	std::cout << std::endl;

	//Test 5: Funcion con punteros const
	const int arrInts2[] = {99, 100}; //podemos ponerle un const o un no const
	const size_t lenInts2 = sizeof(arrStr) / sizeof(arrStr[0]);

	std::cout << std::endl;
	std::cout << "Array de numeros const antes de la fucion: ";
	iter(arrInts2, lenInts2, print<int>);
	std::cout << std::endl;

	iter2(arrInts2, lenInts2, ptrconst<int>);
		
	std::cout << "Array de numeros const después de la fucnion: ";
	iter(arrInts2, lenInts2, print<int>);
	std::cout << std::endl;

	return 0;
}
