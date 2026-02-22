

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat MJ("maria jose", 3);
	Form Iva("303", 2, 1);
	std::cout << Iva;
	MJ.signForm(Iva);
	try {
		MJ.upGrade();
		std::cout << MJ << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what();
	}
	MJ.signForm(Iva);
	std::cout << Iva;
	MJ.signForm(Iva);
	return 0;
}