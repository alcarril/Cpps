#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug (void) const{
	std::cout << DEBUG_MSG << std::endl;
}

void Harl::info (void) const{
	std::cout << INFO_MSG << std::endl;
}

void Harl::warning (void) const{
	std::cout << WARNING << std::endl;
}

void Harl::error (void) const{
	std::cout << ERROR << std::endl;
}

// Arrays of pointers to member functions must be declared specifying that they are
// member functions of the class.
// Memory is declared and initialized with garbage memory addresses by default.
// Then, each function pointer is assigned to the memory address of the class method.
// To access the values, you must specify with the clause this->*funcPtr in C, for example.
// It could be done without the asterisk or with it.
void Harl::complain(std::string level) {
	void (Harl::*funcPtr[4])(void) const;

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
