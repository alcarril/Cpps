

#include "iter.hpp"

int main() {
	// Test 1: array de enteros
	int arrInt[] = {1, 2, 3, 4, 5};
	const size_t lenInt = sizeof(arrInt) / sizeof(arrInt[0]);

	std::cout << "Array de enteros antes de incrementar: ";
	iter(arrInt, lenInt, print<int>);
	std::cout << std::endl;
	
	iter(arrInt, lenInt, increment<int>);

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

	iter(arrStr, lenStr, append_exclamation);

	std::cout << "Array de strings después de append_exclamation: ";
	iter(arrStr, lenStr, print<std::string>);
	std::cout << std::endl;

	return 0;
}
