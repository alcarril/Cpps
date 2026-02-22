
#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Inter default constrcutor called\n";
}

Intern::Intern(const Intern& copy) {
	std::cout << "Inter copy constrcutor called\n";
	*this = copy;
}

Intern::~Intern() {
	std::cout << "Inter default destrcutor called\n";
}

Intern& Intern::operator=(const Intern& copy) {
	std::cout << "Inter copy assignment operator called\n";
	(void)copy;
	return *this;
}

AForm* Intern::createShrubbery(const std::string& target) { 
	return new ShrubberyCreationForm(target); 
}
AForm* Intern::createRobotomy(const std::string& target) { 
	return new RobotomyRequestForm(target); 
}
AForm* Intern::createPresidential(const std::string& target) { 
	return new PresidentialPardonForm(target); 
}

AForm* Intern::makeForm(const std::string formName, const std::string target) {
	struct FormType {
		std::string name;
		AForm* (Intern::*creator)(const std::string&);
	};

	//creacion de diccionario clave valor usando struct
	FormType forms[] = {
		{"shrubbery creation", &Intern::createShrubbery},
		{"robotomy request", &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPresidential}
	};

	for (size_t i = 0; i < sizeof(forms)/sizeof(forms[0]); ++i) {
		if (forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*(forms[i].creator))(target);
		}
	}
	std::cerr << "Error: Form '" << formName << "' does not exist." << std::endl;
	return NULL;
}
