

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

	std::cout << "------------------TESTING BUREAUCRATS------------------\n";

	//declaracion de burocratas con memeria dinamica para mantenerlos que nose autodestruyan
	//despues de salro del scope de try.
	Bureaucrat *_ptrMJ = NULL;
	Bureaucrat *_ptrConcha = NULL;
	Bureaucrat *_ptrJoselu = NULL;
	Bureaucrat *_ptrNotValid = NULL;
	try {
		_ptrMJ = new Bureaucrat("maria jose", 136);
		_ptrConcha = new Bureaucrat("concha", 45);
		_ptrJoselu = new Bureaucrat("jose luis", 5);
		_ptrNotValid = new Bureaucrat("not valid", 0);
	} catch (std::exception& e) {
		std::cerr << "Error adding Bureaucrat: " << e.what();
	}
	std::cout << *_ptrMJ;
	std::cout << *_ptrConcha;
	std::cout << *_ptrJoselu;
	delete _ptrNotValid; //no da segfault aunque no se cree el objeto porque el puntero es NULL
	delete _ptrMJ;
	delete _ptrConcha;
	delete _ptrJoselu;

	std::cout << "------------------TESTING FORMS------------------\n";
	// declaracion de formularios por defecto son todos con rangos de renquerimientos validos
	// por lo que no hace falta try pero se puede meter en un try catch para controlar excepciones de ejecucion
	Bureaucrat* _ptrCurrante;
	std::string BurocrataName = "currante";
	int BurocrataGrade = 1;//cambiando esto se pueden ir lanzando als diferentes excepciones
	try {
		_ptrCurrante = new Bureaucrat(BurocrataName, BurocrataGrade); //cambiando el rango de currante saltarian diferentes exepciones segun el tipo de formulario o del propio rango del buorcrata
	} catch (std::exception& e) {
		std::cerr << "Error adding Bureaucrat: " << e.what();
		return 1;
	}
	std::cout << *_ptrCurrante;


	std::cout << "---------Primer formulario: ShrubberyCreationForm------------\n";
	AForm* _ptrForm;
	std::string firstTarget = "Zona no urbanizable";
	try {
		_ptrForm = new ShrubberyCreationForm(firstTarget);
	} catch (std::exception& e) {
		std::cerr << "Error creating form: " << e.what();
	}
	std::cout << *_ptrForm;
	try {
		_ptrForm->execute(*_ptrCurrante);
	} catch (std::exception& e) {
		std::cerr << "Execution error: " << e.what();
	}
	_ptrCurrante->executeForm(*_ptrForm);
	_ptrForm->singForm(*_ptrCurrante);
	_ptrForm->singForm(*_ptrCurrante);
	try {
		_ptrForm->execute(*_ptrCurrante);
	} catch (std::exception& e) {
		std::cerr << "Execution error: " << e.what();
	}
	_ptrCurrante->executeForm(*_ptrForm);

	delete _ptrForm;

	std::cout << "---------Segundo formulario: RobotomyRequestForm------------\n";
	std::string secondTarget = "Naturistic park";
	try {
		_ptrForm = new RobotomyRequestForm(secondTarget);
	} catch (std::exception& e) {
		std::cerr << "Error creating form: " << e.what() << std::endl;
	}
	std::cout << *_ptrForm;
	try {
		_ptrForm->execute(*_ptrCurrante);
	} catch (std::exception& e) {
		std::cerr << "Execution error: " << e.what();
	}
	_ptrCurrante->executeForm(*_ptrForm);
	_ptrForm->singForm(*_ptrCurrante);
	_ptrForm->singForm(*_ptrCurrante);
	try {
		_ptrForm->execute(*_ptrCurrante);
	} catch (std::exception& e) {
		std::cerr << "Execution error: " << e.what();
	}
	_ptrCurrante->executeForm(*_ptrForm);
	_ptrCurrante->executeForm(*_ptrForm);
	_ptrCurrante->executeForm(*_ptrForm);
	delete _ptrForm;

	std::cout << "---------Tercer formulario: PresidentialPardonForm------------\n";
	std::string thirdTarget = "Zaphod Beeblebrox";
	try {
		_ptrForm = new PresidentialPardonForm(thirdTarget);
	} catch (std::exception& e) {
		std::cerr << "Error creating form: " << e.what();
	}
	std::cout << *_ptrForm;
	
	try {
		_ptrForm->execute(*_ptrCurrante);
	} catch (std::exception& e) {
		std::cerr << "Execution error: " << e.what();
	}
	_ptrCurrante->executeForm(*_ptrForm);
	_ptrForm->singForm(*_ptrCurrante);
	try {
		_ptrForm->execute(*_ptrCurrante);
	} catch (std::exception& e) {
		std::cerr << "Execution error: " << e.what();
	}
	_ptrCurrante->executeForm(*_ptrForm);
	delete _ptrForm;


	delete _ptrCurrante;
}
