

#include "Array.hpp"

int main() {
	//Declaraciones de arrays de int
	Array<int> numbers(5);
	Array<int> copy(numbers);
	const Array<int> constArray(3);
	//declaraciones de arrays de strings
	Array<std::string> words(3);
	Array<std::string> wordsCopy(words);
	std::cout << "Sizes:\n";
	std::cout << "numbers: " << numbers.size() << "\n";
	std::cout << "words: " << words.size() << "\n\n";
	try {
		for (unsigned int i = 0; i < numbers.size(); ++i)
			numbers[i] = i * 10;
		words[0] = "Hola";
		words[1] = "Mundo";
		words[2] = "Templates";
		for (unsigned int i = 0; i < numbers.size(); ++i)
			std::cout << "numbers[" << i << "] = " << numbers[i] << "\n";
		std::cout << "\n";
		for (unsigned int i = 0; i < words.size(); ++i)
			std::cout << "words[" << i << "] = " << words[i] << "\n";
		std::cout << "\n";
		wordsCopy[0] = "Cambio";
		std::cout << "words[0] = " << words[0] << "\n";
		std::cout << "wordsCopy[0] = " << wordsCopy[0] << "\n\n";
		std::cout << numbers[10] << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Excepción capturada: " << e.what() << "\n";
	}
	// words = numbers;//esto falla porque son clases con templetate instanciadas con diferentes tipos
	try {
		words[3] = "pepe";
	} catch (const std::exception& e) {
		std::cerr << "Fallo en el acceso al array " << e.what() << "\n";
	}
	return 0;
}
