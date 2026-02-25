
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>


class ScalarConverter
{
	public:
		static void converter(char* input);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		static void printChar(double converDouble);
		static void printInt(double converDouble);
		static void printFloat(double converDouble);
} ;

#endif