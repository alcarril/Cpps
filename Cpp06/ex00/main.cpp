

#include "ScalarConverter.hpp"

int main(int argz, char** argv)
{
	if (argz != 2) {
		std::cerr << "Nedd more arguments\n";
		return (1);
	}
	if (argv[1] == NULL)
		return (1);
	ScalarConverter::converter(argv[1]);
	return(0);
}