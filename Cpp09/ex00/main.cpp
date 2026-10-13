
#include "BitcoinExchange.hpp"

int main(int argz, char **argv)
{
	if (argz > 2) {
		std::cerr << "This program needs only one argument [./btc <filepath>]\n";
		return 1;
	}
	if (argz < 2) {
		std::cerr << "Error: could not open file\n";
		return 1;
	}
	try {
		BitcoinExchange Exchage;
		Exchage.setInput(std::string(argv[1]));
		Exchage.PrintExchangePOT();
	} catch (std::exception& e) {
		std::cerr << "Loading DataBase Error: " << e.what();
		return 1;
	}
	return 0;
}

/*
	Como romperlo, control de errores parseo:
		Fechas invalidas:
			No tener el formato años-mes-dia
			Fechas a futuro
			Meses con mas dias de os que deben ser
			Febrero
		Formato de imput.txt (pricesovertime):
			No tener los tres campos separados por espacios
			Que no exista la linea numero 1 con el encabezado
			estando vacio
			solo tener el encabezado
			Campo 1 (fecha): no seguir la reglas de formto de fecha
			Campo 2 (barra): ser otro caracter
			Campo 3 (valor):
				no ser un numero o tener caracteres invalidos
				hacer overflow
				puede ser float
				puede ser decimal
				ser un numero negativo o mayor de 1000
		Formato de data.csv (el precio del bitcoin)
			no tener el foramto de fecha separador de coma y valor
			nombre del archivo ser data.csv
			no tener la linea 1 con el encabezado
			estando vacio
			solo tener el encabezado
			Campo 1 (fecha): no seguir las reglas de la fechas
			Campo 2 (valor):
				no ser un numero o tener caracteres invalidos
				hacer overflow
				puede ser float
				puede ser decimal
		Mach de pricesovertime y datacsv:
			Que cuando se busca el valor en esa fecha y no se encuentra
			no te quedes con el valor anterior
			que el valor anterior sea el ultimo valor que se tenga en la base de datos
			que no haya valor anterior porque sea un fecha menor a la primera fecha de la base de datos
*/