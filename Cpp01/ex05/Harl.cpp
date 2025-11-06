

#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug (void)
{
	std::cout << DEBUG_MSG << std::endl;
}

void Harl::info (void)
{
	std::cout << INFO_MSG << std::endl;
}

void Harl::warning (void)
{
	std::cout << WARNING << std::endl;
}

void Harl::error (void) 
{
	std::cout << ERROR << std::endl;
}

//los array de punteros a funciones mienbro se tiene que declarar especificando que es 
//a funciones mienro de la clase
//Se declarla memeria y que esta con una direccion de memeria basura por defecto
//despues se asigna cada puntero de la funcion a la direccion de memoria del metodo de la clase
//para acceder a los valores tiens que especificar con la clausula this->*funcPtr en C por ejemplo
//se podria hacer sin poner el asterisco o ponendolo
void Harl::complain(std::string level)
{
	void (Harl::*funcPtr[4])(void);
	funcPtr[0] = &Harl::debug;
	funcPtr[1] = &Harl::info;
	funcPtr[2] = &Harl::warning;
	funcPtr[3] = &Harl::error;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) 
	{
		if (levels[i] == level) 
		{
			(this->*funcPtr[i])(); 
			return;
		}
	}
	std::cout << "Invalid level: " << level << std::endl;
}
