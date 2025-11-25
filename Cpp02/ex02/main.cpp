

#include "Fixed.hpp"

int main(void) 
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	/////////////my test//////


		std::cout << "\n\n\nMy test \n\n\n";
		Fixed c;
		c = a;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		//pruebas de resto de operaciones con Fixed objects

		std::cout << "\nOperaciones aritmeticas\n\n";
		Fixed d(2);
		Fixed e(4);
		Fixed m(3);
		std::cout << d << std::endl;
		std::cout << e << std::endl;
		Fixed z = e + d;
		Fixed _sumNormal(e + d);
		std::cout << "test sum: " << (e += d) << std::endl;
		std::cout << "test sum normal: " << e + d << std::endl;//
		std::cout << "test sum normal asignacion: " << z << std::endl;
		std::cout << "test sum normal contructor: " << _sumNormal << std::endl;
		z = e - d;
		Fixed _substraction(e - d);
		std::cout << "test substraction: " << (e -= d) << std::endl;
		std::cout << "test substraction normal: " << e - d << std::endl;//
		std::cout << "test substraction normal asignacion: " << z << std::endl;
		std::cout << "test substraction normal construcor: " << _substraction << std::endl;
		z = e * d;
		Fixed _product(e * d);
		std::cout << "test product: " << (e *= d) << std::endl;
		std::cout << "test product normal: " << e * d << std::endl;//
		std::cout << "test product normal asignacion: " << z << std::endl;
		std::cout << "test product normal constructor: " << _product << std::endl;
		z = e / d;
		Fixed _factor(e / d);
		std::cout << "test factor: " << (e /= d) << std::endl;
		std::cout << "test factor normal: " << (e / d) << std::endl;//
		std::cout << "test factor normal asignacion: " << z << std::endl;
		std::cout << "test factor normal constrcutor: " << _factor << std::endl;

		///test division by zero//
		try {
			Fixed z = e / 0; // Intento de división por cero
			std::cout << "test division by zero: " << z << std::endl;
		} catch (const std::runtime_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		Fixed comb = e + d + m;
		std::cout << "test comb sum: " << comb << std::endl;
		comb = e - d - m;
		std::cout << "test comb rest: " << comb << std::endl;
		comb = e * d * m;
		std::cout << "test comb prod: " << comb << std::endl;
		comb = e / d / m;
		std::cout << "test comb factor: " << comb << std::endl;


		////test de operacions logicas de c de comparacion entre objeto fixed


		std::cout << "\n\ntest de operaciones logicas entre fixed format\n\n";
		if (e > d)
			std::cout << "El mayor es e\n";
		else if (e < d)
			std::cout << "El mayor es d\n";
		
		if ((d * 2) == e)
			std::cout << "iguales\n";
		else if ((d * 2) != e) //llama al constrcutor de int de Fixed format lo hace C++ autom,aticamente
			std::cout << "diferentes\n";

		//test de polimorfismo adddhoc en metedos mimbre

		std::cout << "\n\ntest de polimitfosmo addhoc en funciones mienbro\n\n";
		Fixed const _consta(3.12f);
		Fixed const _constb(4.566f);
		Fixed _c(8);
		Fixed _d(2);
		Fixed const _constResult;
		Fixed _result;
		std::cout << Fixed::min(_c, _d) << std::endl;
		std::cout << Fixed::max(_c, _d) << std::endl;
		std::cout << Fixed::min(_consta, _constb) << std::endl;
		std::cout << Fixed::max(_consta, _constb) << std::endl;


		_result = Fixed::min(_consta, _c);//cuando se iguala un objeto constatnte a uno no constatnte como se copian los valores no pasa nada
		_result = Fixed::min(_d, _c);//esto deberia funcionar

		
		// Fixed& _resulta = Fixed::min(_consta, _c);//->no se puede igualar un referencia no constatnte a un constante
		// Fixed& _resultb = Fixed::min(_d, _c);//esto si funciona porque las referencias del minmo tipo si se pueden igualar
		// Fixed& _resultc = _consta;//esto si funciona porque las referencias del minmo tipo si se pueden igualar
		//Un oonjeto si que se puede igualar a una referencia sea constante o no porque se igualan los campos
		//uno a uno
		//una referncia se puede igualar a un objeto u otra referncia solo si es del mimo tipo costante o no constane


	/////////////////// my test end///////

	////pruebas de referencias constantes y no constantes: polimorfismo add hoc metodos///

		//para comprobar el min con const: como el operador
		//de sobrecarga recibe referencias constantes a  los objetos
		//puede reciribir una constante o una no constante
		// std::cout << Fixed::min(a, b) << std::endl;//->prueba
	
		//1.ahora lo que no se puede hacer es usar la funcion para
		//devolver una referencia comstatmte eigualarla a una referncia
		//no constate.
		// Fixed& f = Fixed::min(a, b);//-> no fucniona

		//2.Esto funcion porque devulve un referncias de un objeto que 
		//esta en la memeria local de su misma dependencia por lo que el abito 
		//de la variable sigue no se destruye e inclute a esta. despues se usa
		//el poperador de sobrecarga para que funcione
		// Fixed g = Fixed::min(a, b); //->funciona

		//3.es no nos dejaaira modificar el objeto a traves de la referncia porque
		//es const. aun asi es un forma de poder devolver punteros o direcciones de
		//memeria en un funcion y modificarlas
		// Fixed::min(a, b) = Fixed(1.0f); ->no fucniona

		//......
	////
	return (0);
}
