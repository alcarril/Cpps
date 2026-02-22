

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;

	// Prueba con formularios válidos
	AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "Garden");
	AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Alice");

	// Prueba con formulario inválido
	AForm* form4 = someRandomIntern.makeForm("invalid form", "Nobody");

	// Libera memoria
	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return 0;
}

