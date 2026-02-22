

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat MJ("maria jose", 3);
	Form Iva("303", 2, 1);
	std::cout << Iva;
	Iva.singForm(MJ);
	try {
		MJ.upGrade();
		std::cout << MJ << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what();
	}
	Iva.singForm(MJ);
	std::cout << Iva;
	Iva.singForm(MJ);
	return 0;
}