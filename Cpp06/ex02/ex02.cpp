
#include "ex02.hpp"

Base * generate(void) {
	Base *_ptrRet;
	int randomIdx = createRandomNum();
	if (randomIdx == 0)
		_ptrRet = new A;
	else if (randomIdx == 1)
		_ptrRet = new B;
	else
		_ptrRet = new C;
	return _ptrRet;
}

void identify(Base* p) {
	A* _Aptr = dynamic_cast<A*>(p);
	if (_Aptr != NULL)
		std::cout << "A\n";
	B* _Bptr = dynamic_cast<B*>(p);
	if (_Bptr != NULL)
		std::cout << "B\n";
	C* _Cptr = dynamic_cast<C*>(p);
	if (_Cptr != NULL)
		std::cout << "C\n";
}


void identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A\n";
	} catch (std::exception&) { }
	try {
		dynamic_cast<B&>(p);
		std::cout << "B\n";
	} catch (std::exception&) { }
	try {
		dynamic_cast<C&>(p);
		std::cout << "C\n";
	} catch (std::exception&) { }
}

int createRandomNum(void) {
	std::srand(std::time(0));
	int random_number = std::rand();
	return random_number % 3;
}