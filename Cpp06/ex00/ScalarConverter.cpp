

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {} ;

ScalarConverter::~ScalarConverter() {} ;

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
} ;

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
	(void)copy;
	return *this;
} ;

void ScalarConverter::converter(char * input) {
	if (input == NULL || *input == '\0') {
		std::cerr << "Invalid input no convertsion posible\n";
		return ;
	}

	char *endString;
	errno = 0;
	double convertDouble = strtod(input, &endString);

	if (errno == ERANGE) {
		std::cerr << "Invalid input: buffer overflow/underflow\n";
		return ;
	}
	if (*endString != '\0' && !((*endString == 'f' && *(endString + 1) == '\0'))) {
		if (endString == input && *(input + 1) == '\0') {
			printTypeChar(static_cast<unsigned char>(*input));
			return ;
		}
		std::cerr << "Invalid imput format: no posible conversion\n";
		return ;
	}
	if (std::isnan(convertDouble))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return;
	}
	if (std::isinf(convertDouble))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";

		if (convertDouble < 0)
		{
			std::cout << "float: -inff\n";
			std::cout << "double: -inf\n";
		}
		else
		{
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";
		}
		return;
	}
	printChar(convertDouble);
	printInt(convertDouble);
	printFloat(convertDouble);
	std::cout << "double: " << static_cast<double>(convertDouble);
	if (convertDouble == static_cast<int>(convertDouble))
		std::cout << ".0";
	std::cout << "\n";
}


void ScalarConverter::printChar(double convertDouble) {
	if (convertDouble < CHAR_MIN || convertDouble > CHAR_MAX)
		std::cout << "char: out of range\n";
	else {
		char c = static_cast<char>(convertDouble);
		if (isprint(c))
			std::cout << "char: '" << c << "'\n";
		else
			std::cerr << "char: Non displayable\n";
	}
}

void ScalarConverter::printTypeChar(unsigned char caracter) {
	if (caracter < CHAR_MIN || caracter > CHAR_MAX)
		std::cout << "char: out of range\n";
	else {
		char c = static_cast<char>(caracter);
		if (isprint(c))
			std::cout << "char: '" << c << "'\n";
		else
			std::cerr << "char: Non displayable\n";
	}
}

void ScalarConverter::printInt(double convertDouble) {
	if (convertDouble < INT_MIN || convertDouble > INT_MAX)
		std::cerr << "int: out of range\n";
	else
		std::cout << "int: " << static_cast<int>(convertDouble) << "\n";
}

void ScalarConverter::printFloat(double convertDouble) {
	if (convertDouble > FLT_MAX || convertDouble < -FLT_MAX)
		std::cerr << "float: out of range\n";
	else {
		float f = static_cast<float>(convertDouble);
		std::cout << "float: " << f;
		if (f == static_cast<int>(convertDouble)) 
			std::cout << ".0";
		std::cout << "f\n";
	}
}