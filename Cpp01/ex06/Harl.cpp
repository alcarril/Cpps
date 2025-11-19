#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug (void) {
	std::cout << "[ DEBUG ]\n" << DEBUG_MSG << std::endl;
}

void Harl::info (void) {
	std::cout << "[ INFO ]\n" << INFO_MSG << std::endl;
}

void Harl::warning (void) {
	std::cout << "[ WARNING ]\n" << WARNING << std::endl;
}

void Harl::error (void) {
	std::cout << "[ ERROR ]\n" << ERROR << std::endl;
}

// Arrays of pointers to member functions must be declared specifying that they are
// member functions of the class.
// Memory is declared and initialized with garbage memory addresses by default.
// Then, each function pointer is assigned to the memory address of the class method.
// To access the values, you must specify with the clause this->*funcPtr in C, for example.
// It could be done without the asterisk or with it.
void Harl::complain(std::string level) {
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
