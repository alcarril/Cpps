
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "ex02.hpp"

int main(void) {
	Base* ptr;

	ptr = generate();
	Base& ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
	return (1);
}