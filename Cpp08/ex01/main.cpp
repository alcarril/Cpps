

#include "Span.hpp"
// lo importante es usar los metoods de la libreai algortidh, y cuidar lo limites con operador
// de copia, se puede segun comose mmeta addnumber y copia por defecto.
int main(void) {
	Span Default;
	try {
		Default.addNumber(5);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Span ConstructorSpan(3);
	try {
		ConstructorSpan.addNumber(5);
		ConstructorSpan.addNumber(-12);
		ConstructorSpan.addNumber(2);
		//aqui se pueden añadir elementos
		int longest = ConstructorSpan.longestSpan();
		std::cout << "la mayor diferencias es : " << longest << std::endl;
		int sortest = ConstructorSpan.shortestSpan();
		std::cout << "la menor diferencias es: " << sortest << std::endl;
		ConstructorSpan.generateRandomNumbers(3);
		int longest1 = ConstructorSpan.longestSpan();
		std::cout << "la mayor diferencias es : " << longest1 << std::endl;
		int sortest1 = ConstructorSpan.shortestSpan();
		std::cout << "la menor diferencias es: " << sortest1 << std::endl;
		ConstructorSpan.generateRandomNumbers(1);// Para probar limites del de copia
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Span ConstructorSpan1(2);
	try {
		ConstructorSpan1.addNumber(78);
		ConstructorSpan1.addNumber(78);
		//aqui se pueden añadir elementos
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Span CopyConstructorSpan(ConstructorSpan1);
	try {
		int longest2 = CopyConstructorSpan.longestSpan();
		std::cout << "la mayor diferencias es : " << longest2 << std::endl;
		int sortest2 = CopyConstructorSpan.shortestSpan();
		std::cout << "la menor diferencias es: " << sortest2 << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	 
	CopyConstructorSpan = ConstructorSpan;
	try {
		std::cout << CopyConstructorSpan.longestSpan() << std::endl;
		std::cout << CopyConstructorSpan.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}	