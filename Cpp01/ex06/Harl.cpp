#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug (void)
{
	std::cout << "[ DEBUG ]\n" << DEBUG_MSG << std::endl;
}

void Harl::info (void)
{
	std::cout << "[ INFO ]\n" << INFO_MSG << std::endl;
}

void Harl::warning (void)
{
	std::cout << "[ WARNING ]\n" << WARNING << std::endl;
}

void Harl::error (void) 
{
	std::cout << "[ ERROR ]\n" << ERROR << std::endl;
}

//los array de punteros a funciones mienbro se tiene que declarar especificando que es 
//a funciones mienro de la clase
//Se declarla memeria y que esta con una direccion de memeria basura por defecto
//despues se asigna cada puntero de la funcion a la direccion de memoria del metodo de la clase
//para acceder a los valores tiens que especificar con la clausula this->*funcPtr en C por ejemplo
//se podria hacer sin poner el asterisco o ponendolo
void Harl::complain(std::string level)
{
	int levelNum;

	if (level == "DEBUG")
		levelNum = DEBUG_L;
	else if (level == "INFO")
		levelNum = INFO_L;
	else if (level == "WARNING")
		levelNum = WARNING_L;
	else if (level == "ERROR")
		levelNum = ERROR_L;
	else 
		levelNum = -1;

	void (Harl::*funcPtr[4])(void);
	funcPtr[0] = &Harl::debug;
	funcPtr[1] = &Harl::info;
	funcPtr[2] = &Harl::warning;
	funcPtr[3] = &Harl::error;

	switch (levelNum)
	{
		case DEBUG_L:
			(this->*funcPtr[DEBUG_L])();
			std::cout << std::endl;
			/* FALLTHROUGH */

		case INFO_L:
			(this->*funcPtr[INFO_L])();
			std::cout << std::endl;
			/* FALLTHROUGH */
			
		case WARNING_L:
			(this->*funcPtr[WARNING_L])();
			std::cout << std::endl;
			/* FALLTHROUGH */
	
		case ERROR_L:
			(this->*funcPtr[ERROR_L])();
			std::cout << std::endl;
			break ;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << std::endl;
			break;
	}
}
