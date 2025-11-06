

#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	/////////////mis pruebas//////
		// Fixed c;
		// c = a;
		// std::cout << a << std::endl;
		// std::cout << b << std::endl;
		// std::cout << c << std::endl;
		// //pruebas de resto de operaciones con Fixed objects
		// Fixed d(2);
		// Fixed e(4);
		// std::cout << "test sum: " << (e += d) << std::endl;
		// std::cout << "test sum: " << e + d << std::endl;
		// std::cout << "test substraction: " << e - d << std::endl;
		// std::cout << "test substraction: " << (e -= d) << std::endl;
		// std::cout << "test product: " << e * d << std::endl;
		// std::cout << "test product: " << (e *= d) << std::endl;
		// std::cout << "test factor: " << (e /= d) << std::endl;//->no funciona
		// std::cout << "test factor: " << (e / d) << std::endl;
	//////////////

	////pruebas de referencias constantes y no constantes:///

		//para comprobar el min con const: como el operador
		//de sobrecarga recibe referencias constantes a  los objetos
		//puede reciribir una constante o una no constante
		// std::cout << Fixed::min(a, b) << std::endl;->prueba
	
		//1.ahora lo que no se puede hacer es usar la funcion para
		//devolver una referencia comstatmte eigualarla a una referncia
		//no constate.
		// Fixed& f = Fixed::min(a, b);-> no fucniona

		//2.esto si va bien porque se crea una copia desde
		//los valores de la referencia constante devuelta por min
		// Fixed g = Fixed::min(a, b); ->funciona

		//3.es no nos dejaaira modificar el objeto a traves de la referncia porque
		//es const
		// Fixed::min(a, b) = Fixed(1.0f); ->no fucniona

		//......
	////

	return (0);
}
