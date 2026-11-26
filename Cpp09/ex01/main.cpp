
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
	Exercise rules:
		There is always a space between operators
		Elements are either operators or numbers smaller than 10
		Valid symbols: + - * /
		No parentheses
	RPN rules (which complement the rules above):
		When an operator is found, at least two operands must be in the stack -> The input always starts with two numbers / There can never be more operators than accumulated numbers / There is always one fewer operator than operands
		At the end, no more than one number may remain on the stack: no extra numbers or operators
	Valid expressions:
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