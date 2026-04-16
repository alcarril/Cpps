
#include "MutantStack.hpp"

int main(void) {
	MutantStack<int> Mutant;
	std::cout << "El size o tamaño de mutant es: " << Mutant.size() << std::endl;
	Mutant.push(5);
	std::cout << "El primer valor de Mutant es: " << Mutant.top() << std::endl;
	Mutant.push(7);
	std::cout << "El primer valor de Mutant es: " << Mutant.top() << std::endl;
	Mutant.pop();
	std::cout << "El primer valor de Mutant despues del pop vuelev a ser: " << Mutant.top() << std::endl;
	Mutant.clear();
	std::cout << "El size o tamaño de mutant despues de clear es: " << Mutant.size() << std::endl;
	
	Mutant.push(777);
	Mutant.push(888);
	MutantStack<int>::iterator it;
	it = Mutant.begin();
	std::cout << "El valor del iterador es: " << *it << std::endl;
	std::cout << "La direccion de memeria a la que apunta el iterador es: " << &(*it) << std::endl;
	++it;
	std::cout << "El valor del iterador depues de aumnetarlo es: " << *it << std::endl;
	std::cout << "La direccion de memeria a la que apunta el iterador es: " << &(*it) << std::endl;
	it--;
	std::cout << "El valor del iterador depues de aumnetarlo es: " << *it << std::endl;
	std::cout << "La direccion de memeria a la que apunta el iterador es: " << &(*it) << std::endl;
	MutantStack<int>::iterator itend;
	itend = Mutant.end();
	for (; it != itend; it++) {
		std::cout << *it << std::endl;
	}
	std::stack<int> s(Mutant);
	std::cout << "El size de s es: " << s.size() << std::endl;
}