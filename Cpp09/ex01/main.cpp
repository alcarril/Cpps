
#include "RPN.hpp"

int main(int argz, char **argv)
{
	if (argz != 2) {
		std::cerr << "Format './RNP \"<args>\"'";
		return 1;
	}
	RPN operatorClass;
	operatorClass.setInput(std::string(argv[1]));
	try {
		operatorClass.DiplayRPN();
	} catch (std::exception& e) {
		std::cerr << e.what();
		return 1;
	}
	return 0;
}

/*
	Reglas de ejericio
		Siempre hay un espacio entre opradores
		O son operadores o numeros menores a 10
		Simbolos validos: + - * /
		No hay parentesis
	Reglas RNP (aunas esogen a las otras)
		Cuando te encuentra un operador tiene quehaber alnso dos operandos en la pila ->El inico simepre tiene dos numeros / Nunca puedes tener mas operadores que numeros acumulados /Simpre hay un operador menos que numero de operandos
		Al final no puede haber mas de un numero en la pila: ni nuemros ni operadores
	Expresiones validas
		"1 2 +"
		"1 2 -"
		"1 2 *"
		"1 2 /"
		"1 2 + 3 *"
		"1 2 + 3 -"
		"1 2 + 3 /"
		"1 2 + 3 * 4 -"
		"1 2 + 3 * 4 /"
		"5 3 2 * +"

*/