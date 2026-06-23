

#include "ScalarConverter.hpp"

int main(int argz, char** argv)
{
	if (argz != 2) {
		std::cerr << "Nedd more arguments\n";
		return (1);
	}
	if (argv[1] == NULL)
		return (1);
	std::string stringImput(argv[1]);
	ScalarConverter::converter(stringImput);
	/*
		//Comprobacion de los formatos validdos de los floats por el compilador:
		// float a = 44f; //este no deberia dejarlo ponerlo asi el parseador de compilador
		float b = 53.f; //esta sintaxi la admite el compilador
		std::cout << b << std::endl;
		(void)b;
		float c = 99.0f; //este si que es un foramto valido
		std::cout << c << std::endl;
		(void)c;
		float d = .56f; //esta sintaxis la admite el compilador
		std::cout << d << std::endl;
		(void)d;
		float e = 55.; //esta sintaxis la admite el compilador
		std::cout << e << std::endl;
		(void)e;
		float i = .77.f:
		(void)i;
	*/

	return(0);
}