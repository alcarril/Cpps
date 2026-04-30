
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