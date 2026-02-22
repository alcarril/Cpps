

#include "Bureaucrat.hpp"

int main(void) {
	//prueba de crear unburocrata que esta en los rangos que debe estar
	try {
		Bureaucrat uno("uno", 3);
		std::cout << uno << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what();
		return (1);
	}
	//prueba de varias accciones dentro de un try
	try {
		Bureaucrat dos("dos", 2);
		dos.upGrade();
		dos.upGrade();//esta linea va a lanzar una excepcion (si no la cocomntamos)
		dos.downGrade();
		Bureaucrat tres("tres", 149);
		tres.downGrade();
		tres.downGrade();//esta linea va a lanzar una excepcion (si no la cocommentamos)
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what();
	}
	// std::cout << uno << std::endl; // esta comentada porque el compiladro se queja porque el objeto deja de existr
	std::cout << "el codigo sigue pese a los cath siempre que este fuera del cath\n";

	///////////pruebas de practicas no recomnendadas (comentadas al principio)///////////
	std::cout << "prueba de creacion fuera de bloqyue try para maneter el objeto en memria\n\n";
	//prueba de crear un birocrata sin un try que fucnoines (no es recomendable), si el objeto 
	//se crea con un grado fuera de rango, el programa se va a cerrar por la excepcion uncaught y core dumped
	Bureaucrat b("norecomendgood", 148);
	try {
		b.downGrade();
		b.downGrade();
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what();
	}
	std::cout << b << std::endl;
}
